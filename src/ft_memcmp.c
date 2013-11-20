/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:47 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 17:18:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ps1;
	char	*ps2;

	ps1 = (char*)s1;
	ps2 = (char*)s2;
	if (!n )
		return (0);
	while (*ps1 == *ps2)
	{
		ps1 ++;
		ps2 ++;
	}
	if (ps2 > ps1)
		return ((int)(ps2 - ps1));
	return ((int)(ps1 - ps2));
}
