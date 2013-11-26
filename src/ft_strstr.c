/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:21:32 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 13:55:00 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s2);
	ptr = (char*)s1;
	if (!s2 || !s1)
		return (NULL);
	while (*ptr && (ptr = ft_strchr(s1, *s2)) != 0)
	{
		if (!ft_strncmp(ptr, s2, len))
			return (ptr);
		ptr ++;
	}
	return (NULL);
}
