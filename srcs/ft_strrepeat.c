/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:19:17 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:19:35 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char					*ft_strrepeat(char *dest,
									size_t const n,
									char const *src,
									size_t const limit)
{
	size_t				i;
	size_t				bigi;
	size_t				srclen;
	size_t				times;

	if (!dest || !src)
		return (dest);
	times = 0;
	bigi = 0;
	srclen = ft_strlen(src);
	while (bigi < n)
	{
		if (limit && times >= limit)
			break ;
		i = 0;
		while (i < srclen && bigi < n)
		{
			dest[bigi] = src[i];
			bigi++;
			i++;
		}
		times++;
	}
	dest[bigi] = '\0';
	return (dest);
}
