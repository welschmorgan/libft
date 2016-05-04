/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:39:21 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:09:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putnbr_fd(int num, int fd)
{
	static char	buf[32];
	char		*pbuf;
	unsigned	m;
	unsigned	d;
	int			s;

	ft_bzero((void*)buf, 32 * sizeof(char));
	s = num < 0 ? -1 : 1;
	d = (unsigned)(((long)num) * s);
	m = d % 10;
	pbuf = &buf[0] + (sizeof(buf) / sizeof(char));
	*pbuf-- = 0;
	if (!num)
		*pbuf-- = '0';
	while (d > 0 && pbuf >= &buf[0])
	{
		*pbuf-- = '0' + m;
		d /= 10;
		m = d % 10;
	}
	if (s < 0)
		*pbuf-- = '-';
	pbuf++;
	return (ft_putstr_fd(pbuf, fd));
}
