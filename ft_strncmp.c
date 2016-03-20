/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:31:50 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 11:10:38 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const t_uchar	*ps1;
	const t_uchar	*ps2;
	size_t			i;

	if (!n)
		return (0);
	i = 0;
	ps1 = (const t_uchar *)s1;
	ps2 = (const t_uchar *)s2;
	while (i < n)
	{
		if (!(*ps1 || *ps2) || (*ps1 != *ps2))
			return ((int)(((unsigned char)*ps1) - (unsigned char)*ps2));
		ps1++;
		ps2++;
		i++;
	}
	return (0);
}
