/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:29:59 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:46:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t						ft_wstrlcat(wchar_t *dest,
										const wchar_t *src,
										size_t size)
{
	wchar_t			*d;
	const wchar_t	*s;
	size_t			n;
	size_t			dlen;

	d = dest;
	s = src;
	n = size;
	while (n-- && *d)
		d++;
	dlen = d - dest;
	n = size - dlen;
	if (!n)
		return (dlen + ft_wstrlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
