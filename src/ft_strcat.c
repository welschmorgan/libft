/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:23:39 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 18:46:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy(dest + ft_strlen(src), src);
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	ft_strncpy(dest + len, src, (len > n ? n : len));
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if ((slen + dlen) >= size)
		return (slen + dlen);
	ft_strncpy(dest + dlen, src, slen);
	return (dlen + slen);
}
