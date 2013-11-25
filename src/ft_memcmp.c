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
	const t_uchar	*ps1;
	const t_uchar	*ps2;

	ps1 = (const t_uchar *)s1;
	ps2 = (const t_uchar *)s2;
	if (!n || !(ps1 && ps2))
		return (0);
	while (*(ps1++) == *(ps2++) && n--);
	return ((int)(ps1 - ps2));
}
