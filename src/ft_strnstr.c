/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:07:09 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 20:15:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*orig;

	while (s1 && *s1 && s2 && *s2 && n)
	{
		if (*s1 == *s2)
			orig = s1;
		else
			n --;
		while (*s1 == *s2 && n)
		{
			s1 ++;
			s2 ++;
			n --;
		}
		if (*s2 == '\0')
			return ((char*)orig);
	}
	return (NULL);
}
