/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:17:02 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 18:49:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (int)((unsigned char *)s2 - (unsigned char *)s1);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	return (int)((unsigned char *)s2 - (unsigned char *)s1);
}
