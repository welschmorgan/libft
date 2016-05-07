/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 12:51:34 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/07 19:22:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char				*ft_float_string(t_float *f)
{
	static char		smlbuf[33] = {0};
	static char		bigbuf[33] = {0};
	int				len;
	int				i;
	char			*data;

	len = 0;
	ft_memset((void*)smlbuf, 0, 32 * sizeof(char));
	ft_memset((void*)bigbuf, 0, 32 * sizeof(char));
	ft_strncpy(bigbuf, ft_ibtoa_s(f->ipart, f->base, smlbuf, 32), 32 - len);
	len = ft_strlen(bigbuf);
	if (f->precision != 0)
	{
		ft_strncpy(bigbuf + len, ".", 32 - len);
		len = ft_strlen(bigbuf);
		data = ft_ibtoa_s((int)f->fpart, f->base, smlbuf, 32);
		if (((int)ft_strlen(data)) > f->precision)
			data[f->precision] = 0;
		else
		{
			i = ft_strlen(data);
			while (i < f->precision)
				data[i++] = '0';
			data[i] = 0;
		}
		ft_strncpy(bigbuf + len, data, 32 - len);
		len = ft_strlen(bigbuf);
	}
	bigbuf[len] = 0;
	return (bigbuf);
}

int					ft_float_init(t_float *f,
							  float val,
							  int precision,
							  unsigned base)
{
	f->value = val;
	f->sign = ft_bit((const char *)&val, sizeof(float), 31);
	f->exponent = 0;
	f->precision = ((precision < 0)
					? 6
					: (precision > 7
					   ? 7
					   : precision));
	f->base = base;
	f->ipart = (int)ft_float_fabs(val);
	f->fpart = ft_float_fabs(ft_float_fabs(f->value) - (float)f->ipart);
	f->fpart *= ft_float_powf(10.0f, ft_float_fabs((float)f->precision));
	f->ipart_len = ft_log10u((unsigned)f->ipart);
	f->fpart_len = ft_log10u((unsigned)f->fpart);
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
							 int precision,
							 unsigned base)
{
	t_float			flt;
	char			*data;

	ft_float_init(&flt, f, precision, base);
	data = ft_float_string(&flt);
	if (data)
		data = ft_strdup(data);
	return (data);
}
