/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_string_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:02:03 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 13:09:48 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"
#include "libft_string.h"

char						*ft_float_iee754_string_dec(t_float_iee754 *f)
{
	char					max;
	char					*dec;

	*f->offset++ = '.';
	if (f->decimal == 0)
	{
		max = f->precision > 0 ? f->precision : FT_FLOAT_PRECISION;
		ft_strrepeat(f->offset, max, "0", 0);
		f->offset += max;
	}
	else
	{
		dec = 0;
		ft_float_iee754_string_decdo(f, dec);
		ft_float_iee754_string_finalize(f, dec);
	}
	return (f->buffer);
}

char						*ft_float_iee754_string_decdo(t_float_iee754 *f,
														char *dec)
{
	char					max;

	max = sizeof(f->buffer) - (f->offset - f->buffer) - 1;
	if (max > 7)
		max = 7;
	f->precision = f->precision < 0 ? 0 : f->precision;
	if (f->precision > max)
		f->precision = max;
	*dec = 0;
	while (*dec < max)
	{
		f->decimal = (f->decimal << 3) + (f->decimal << 1);
		*f->offset++ = (f->decimal >> 24) + '0';
		f->decimal &= 0xFFFFFF;
		(*dec)++;
	}
	return (f->buffer);
}
