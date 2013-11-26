/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:21:32 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 19:56:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(char const *hstack, char const *needle)
{
	char	*orig;

	if (!needle)
		return ((char*)hstack);
	if (!hstack)
		return (NULL);
	orig = NULL;
	while (*hstack)
	{
		if (*hstack == *needle)
		{
			orig = (char*)hstack;
			while (*hstack == *needle)
			{
				hstack ++;
				needle ++;
			}
			if (*hstack == *needle && *needle == '\0')
				return (orig);
		}
		else
			hstack++;
	}
	return (NULL);
}
