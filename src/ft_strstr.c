/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:21:32 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 20:05:09 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*ptr = s1;
	size_t		len = ft_strlen(s2);

	while ((ptr = ((const char*)ft_strchr (ptr, *s2))) != 0)
	{
		printf("Testing %i chars in %s\n", (int)len, ptr);
		if (!ft_strncmp(ptr, s2, len))
		{
			printf("\tFound: %s\n", ptr);
			return ((char *)ptr);
		}
		ptr ++;
	}
	return (NULL);
}
