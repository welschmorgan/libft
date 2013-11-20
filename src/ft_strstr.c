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

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*orig;

	while (s1 && *s1 && s2 && *s2)
	{
		if (*s1 == *s2)
			orig = s1;
		while (*s1 == *s2)
		{
			s1 ++;
			s2 ++;
		}
		if (*s2 == '\0')
			return ((char*)orig);
	}
	return (NULL);
}
