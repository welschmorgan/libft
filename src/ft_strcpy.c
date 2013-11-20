/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:38:50 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 17:21:17 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*pdest;

	pdest = dest;
	while (src && *src && dest)
	{
		*dest = *src;
		src ++;
		dest ++;
	}
	return (pdest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*pdest;

	pdest = dest;
	while (src && *src && dest && n--)
	{
		*dest = *src;
		src ++;
		dest ++;
	}
	return (pdest);
}
