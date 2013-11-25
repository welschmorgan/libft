/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:35:41 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 14:42:56 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	const unsigned char	*psrc;
	unsigned char		*pdest;

	if (!s1 || !n)
		return (s1);
	psrc = (unsigned char*)s2;
	pdest = (unsigned char *)s1;
	while (psrc && n--)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return ((void*)(pdest + 1));
		psrc ++;
		pdest ++;
	}
	return (NULL);
}
