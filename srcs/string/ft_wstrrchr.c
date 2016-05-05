/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:33:04 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:34:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrrchr(const wchar_t *str, int c)
{
	const wchar_t	*start;
	const wchar_t	*end;
	const wchar_t	*cur;

	start = str;
	end = str + ft_wstrlen(str);
	cur = end;
	while (cur && cur >= start)
	{
		if (*cur == (wchar_t)c)
			return ((wchar_t*)cur);
		cur--;
	}
	return (NULL);
}
