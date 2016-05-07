/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 12:51:34 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/07 13:03:46 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct		s_float
{
	float			value;
	unsigned char	sign;
	unsigned		base;
	unsigned char	exponent;
	unsigned long	mantissa;
	unsigned char	precision;
}					t_float;

static double		ft_float_fabs(double f)
{
	return (f < -FT_EPSILON ? -f : f);
}

static double		ft_float_powf(double x, double y)
{
	float			ret;

	ret = x;
	while (ft_float_fabs(y) > FT_EPSILON)
	{
		ret *= x;
		y -= 1.0f;
	}
	return (ret);
}

static char			*ft_float_string(t_float *f)
{
	float			fpart;
	int				ipart;
	static char		smlbuf[33] = {0};
	static char		bigbuf[33] = {0};
	int				len;

	ipart = (int)f->value;
	fpart = ft_float_fabs(f->value - (float)ipart);
	fpart *= ft_float_powf(10.0f,
					 (float)(f->precision > 0
							 ? f->precision
							 : 0));
	len = 0;
	ft_strncpy(bigbuf, ft_ibtoa_s(ipart, 10, smlbuf, 32), 32 - len);
	len = ft_strlen(bigbuf);
	ft_strncpy(bigbuf + len, ".", 32 - len);
	len = ft_strlen(bigbuf);
	ft_strncpy(bigbuf + len, ft_ibtoa_s((int)fpart, 10, smlbuf, 32), 32 - len);
	if (ft_strlen(bigbuf + len) >= f->precision)
		bigbuf[len + f->precision] = 0;
	len = ft_strlen(bigbuf);
	bigbuf[len] = 0;
	return (bigbuf);
}

static int			ft_float_init(t_float *f,
								  float val,
								  unsigned char precision,
								  unsigned base)
{
	f->value = val;
	f->sign = ft_bit((const char *)&val, sizeof(float), 31);
	f->exponent = 0;
	f->precision = precision;
	f->base = base;
	int i;
	i = 0;
	while (i < 8)
	{
		if (ft_bit((const char *)&val, sizeof(float), 23 + i))
			f->exponent |= 1 << i;
		i++;
	}
	f->mantissa = 0;
	i = 0;
	while (i < 23)
	{
		if (ft_bit((const char *)&val, sizeof(float), i))
			f->mantissa |= 1 << i;
		i++;
	}
	return (0);
}

char				*ft_ftoa(float f,
							 unsigned char precision,
							 unsigned base)
{
	t_float			flt;

	ft_float_init(&flt, f, precision, base);
	return (ft_float_string(&flt));
}
