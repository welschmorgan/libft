/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:47:44 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 21:14:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa(long num, int base)
{
	static char	buf[65];
	char		*ptr;

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	if (num == 0)
	{
		*--ptr = '0';
		return (ptr);
	}
	while (1)
	{
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	if (num < 0)
		*--ptr = '-';
	return (ptr);
}
