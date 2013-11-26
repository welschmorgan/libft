/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:52:31 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 17:18:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uchar		*dptr;
	const t_uchar	*sptr;
	size_t	i;

	i = 0;
	dptr = (t_uchar*)dest;
	sptr = (const t_uchar *)src;
	if (!n)
		return (dest);
	while (i < n && sptr && dptr)
	{
		dptr[i] = sptr[i];
		i ++;
	}
	return (dest);
}
