/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 20:48:11 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 14:46:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_float_iee754				*ft_float_iee754_init(t_float_iee754 *f,
												float v, int prec)
{
	f->value.f = v;
	f->exponent = 1;
	f->mantissa = 0;
	f->decimal = 0;
	f->whole = 0;
	f->status = 0;
	f->precision = prec;
	ft_memset(f->buffer, 0, FT_FLOAT_SIZE * sizeof(char));
	f->offset = f->buffer;
	if (f->value.l > 0)
	{
		f->exponent = (unsigned char)(f->value.l >> 23) - 127;
		f->mantissa = (f->value.l & 0xFFFFFF) | 0x800000;
	}
	else if (!f->value.l)
		return (f);
	if (f->exponent >= 31)
		f->status = FT_FLOAT_TOO_LARGE;
	else if (f->exponent < -23)
		f->status = FT_FLOAT_TOO_SMALL;
	else if (f->exponent >= 23)
		f->whole = f->mantissa << (f->exponent - 23);
	else if (f->exponent >= 0)
	{
		f->whole = f->mantissa >> (23 - f->exponent);
		f->decimal = (f->mantissa << (f->exponent + 1)) & 0xFFFFFF;
	}
	else
		f->decimal = (f->mantissa & 0xFFFFFF) >> -(f->exponent + 1);
	return (f);
}

int							ft_float_iee754_iszero(t_float_iee754 *f)
{
	return (f
			&& f->value.f > -FT_FLOAT_TOLERANCE
			&& f->value.f < FT_FLOAT_TOLERANCE);
}

char						*ft_float_iee754_string_whole(t_float_iee754 *f)
{
	char					*num;
	int						len;

	f->offset = f->buffer;
	if (ft_float_iee754_iszero(f))
		return (ft_strcpy(f->offset++, "0"));
	if (f->value.f <= -FT_FLOAT_TOLERANCE)
	{
		*f->offset++ = '-';
	}
	if (f->whole == 0)
		*f->offset++ = '0';
	else
	{
		num = ft_ntoa(f->whole, 10);
		len = ft_strlen(num);
		ft_strncpy(f->offset, num, FT_FLOAT_SIZE);
		f->offset += len;
	}
	return (f->buffer);
}

char						*ft_float_iee754_string_decimal(t_float_iee754 *f)
{
	char					max;
	char					dec;

	*f->offset++ = '.';
	if (f->decimal == 0)
	{
		max = f->precision > 0 ? f->precision : FT_FLOAT_PRECISION;
		ft_strrepeat(f->offset, max, "0", 0);
		f->offset += max;
	}
	else
	{
		max = sizeof (f->buffer) - (f->offset - f->buffer) - 1;
		if (max > 7)
			max = 7;
		f->precision = f->precision < 0 ? 0 : f->precision;
		if (f->precision > max)
			f->precision = max;
		dec = 0;
		while (dec < max)
		{
			/* frac_part *= 10;*/
			f->decimal = (f->decimal << 3) + (f->decimal << 1);
			*f->offset++ = (f->decimal >> 24) + '0';
			f->decimal &= 0xFFFFFF;
			dec++;
		}
		while ((f->precision > 0
				? (dec >= f->precision)
				: (dec >= FT_FLOAT_PRECISION))
			   && ft_strncmp(f->offset - 1, ".0", 2))
		{
			--dec;
			--f->offset;
		}
		++f->offset;
		++dec;
		ft_strnround(f->buffer, ft_strlen(f->buffer), (f->offset - f->buffer) / sizeof(char));
	}
	return (f->buffer);
}

char						*ft_float_iee754_string(t_float_iee754 *f)
{
	ft_float_iee754_string_whole(f);
	ft_float_iee754_string_decimal(f);
	return (f->buffer);
}
