/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:43:45 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 10:53:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const t_uchar	*psrc;
	t_uchar			*pdest;

	psrc = (const t_uchar*)src;
	pdest = (t_uchar*)dest;
	if (pdest <= psrc || pdest >= (psrc + n))
	{
		while (n--)
			*(pdest++) = *(psrc++);
	}
	else
	{
		psrc += n - 1;
		pdest += n - 1;
		while (n--)
			*(pdest--) = *(psrc--);
	}
	return (dest);
}
