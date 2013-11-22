/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:50:16 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 19:03:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const t_uchar		*ptr;

	ptr = (const t_uchar *)s;
	while (ptr && n --)
	{
		if (*ptr == (unsigned char)c)
			return ((void*)ptr);
		ptr ++;
	}
	return (NULL);
}
