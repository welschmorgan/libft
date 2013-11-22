/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:54:41 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/19 13:54:43 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pstart;
	unsigned char	*pend;

	if (!b || !len)
		return (b);
	pstart = (unsigned char *)b;
	pend = pstart + len;
	while (pstart != pend)
	{
		*pstart = c;
		pstart ++;
	}
	return (b);
}
