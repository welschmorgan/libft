/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:50:59 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 13:09:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"
#include "libft_memory.h"
#include "libft_string.h"

t_float_iee754				*ft_float_iee754_init(t_float_iee754 *f,
												float v,
												int prec)
{
	f->value.f = v;
	f->exponent = 1;
	f->mantissa = 0;
	f->decimal = 0;
	f->whole = 0;
	f->status = 0;
	f->precision = prec;
	ft_memset(f->buffer, 0, sizeof(char) * FT_FLOAT_SIZE);
	f->offset = f->buffer;
	return (ft_float_iee754_init_fiddle(f));
}

t_float_iee754				*ft_float_iee754_init_fiddle_exp(t_float_iee754 *f)
{
	if (f->exponent >= 31)
	{
		f->status = FT_FLOAT_TOO_LARGE;
	}
	else if (f->exponent < -23)
	{
		f->status = FT_FLOAT_TOO_SMALL;
	}
	else if (f->exponent >= 23)
	{
		f->whole = f->mantissa << (f->exponent - 23);
	}
	else if (f->exponent >= 0)
	{
		f->whole = (f->mantissa >> (23 - f->exponent));
		f->decimal = ((f->mantissa << (f->exponent + 1)) & 0xFFFFFF);
	}
	else
	{
		f->decimal = ((f->mantissa & 0xFFFFFF) >> -(f->exponent + 1));
	}
	return (f);
}

t_float_iee754				*ft_float_iee754_init_fiddle(t_float_iee754 *f)
{
	if (f->value.l > 0)
	{
		f->exponent = ((unsigned char)(f->value.l >> 23) - 127);
		f->mantissa = ((f->value.l & 0xFFFFFF) | 0x800000);
	}
	else if (!f->value.l)
	{
		return (f);
	}
	return (ft_float_iee754_init_fiddle_exp(f));
}
