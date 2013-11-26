/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:31:50 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 14:31:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (s1 && s2)
	{
		return (int)(((unsigned char)*s1) - (unsigned char)*s2);
	}
	return (0);
}
