/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:52:31 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:54:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uchar			*pdest;
	const t_uchar	*psrc;

	if (!dest || !n)
		return (dest);
	pdest = dest;
	psrc = src;
	while (psrc && *psrc && pdest && *pdest && n--)
	{
		*(pdest++) = *(psrc++);
	}
	return (dest);
}
