/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:43:45 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 19:37:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const t_uchar	*psrc;
	t_uchar			*pdest;

	if (dest <= src || dest >= (src + n))
	{
		psrc = (const t_uchar*)src;
		pdest = (t_uchar*)dest;
		while (n-- && psrc && pdest)
		{
			*pdest = *psrc;
			pdest ++;
			psrc ++;
		}
	}
	else
	{
		psrc = (const t_uchar*)(src + n - 1);
		pdest = (t_uchar*)(dest + n - 1);
		while (n -- && psrc && pdest)
		{
			pdest --;
			psrc --;
		}
	}
	return (dest);
}
