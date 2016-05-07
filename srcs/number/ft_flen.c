/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:52:42 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/07 16:25:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_signf(float f)
{
	return (ft_zerof(f) ? -1 : 1);
}

int			ft_zerof(float f)
{
	return (f < -FT_EPSILON);
}

int			ft_flen(float f, int prec)
{
	int		len;
	t_float	flt;

	ft_float_init(&flt, f, prec, 10);
	len = (int)flt.sign;
	len += flt.ipart_len;
	len += flt.fpart_len > prec ? prec : flt.fpart_len;
	if (flt.precision)
		len += 1;
	return (len);
}
