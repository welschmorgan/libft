/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:30:49 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 12:10:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_core(unsigned n, int sign, char *buf, int p)
{
	unsigned	d;
	unsigned	m;

	buf[p--] = 0;
	d = n;
	m = d % 10;
	while (d > 0)
	{
		buf[p--] = '0' + m;
		d /=  10;
		m = d % 10;
	}
	if (sign < 0)
		buf[p--] = '-';
	return (&buf[p + 1]);
}

char		*ft_itoa(int n)
{
	int			p;
	static char	buf[32] = {0};
	int			sign;

	p = sizeof(buf) / sizeof(char);
	sign = n < 0 ? -1 : 1;
	n = (unsigned)(((long)n) * sign);
	if (!n)
	{
		buf[p--] = '0';
		return (&buf[p + 1]);
	}
	return (ft_itoa_core(n, sign, buf, p));
}
