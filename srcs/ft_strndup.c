/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 17:45:07 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/28 05:03:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t max)
{
	char	*dup;
	size_t	len;

	len = src ? FT_MIN(ft_strlen(src), max) : 1;
	dup = ft_strnew(len);
	if (!dup)
		return (NULL);
	if (src)
		ft_strncpy(dup, src, len);
	else
		dup[0] = '\0';
	return (dup);
}
