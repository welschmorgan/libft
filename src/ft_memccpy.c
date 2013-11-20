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

	psrc = s2;
	pdest = s1;
	while (psrc && n > 0)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return (pdest + 1);
		n --;
		psrc ++;
		pdest ++;
	}
	return (NULL);
}
