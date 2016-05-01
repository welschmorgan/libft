/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:37:27 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:38:40 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_wstrncmp(const wchar_t *s1,
										const wchar_t *s2,
										size_t n)
{
	const wchar_t	*ps1;
	const wchar_t	*ps2;
	size_t			i;

	if (!n)
		return (0);
	i = 0;
	ps1 = (const wchar_t *)s1;
	ps2 = (const wchar_t *)s2;
	while (i < n)
	{
		if (!(*ps1 || *ps2) || (*ps1 != *ps2))
			return ((int)(((unsigned int)*ps1) - (unsigned int)*ps2));
		ps1++;
		ps2++;
		i++;
	}
	return (0);
}
