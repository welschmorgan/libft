/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:54:41 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 16:34:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_uchar		*pstart;
	t_uchar		*pend;

	if (!b || !len)
		return (b);
	pstart = (unsigned char *)b;
	pend = pstart + len;
	while (pstart < pend)
	{
		*pstart = (unsigned char)c;
		pstart++;
	}
	return (b);
}
