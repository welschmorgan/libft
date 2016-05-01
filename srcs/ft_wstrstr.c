/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:34:17 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:48:17 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrstr(const wchar_t *hstack,
										const wchar_t *needle)
{
	wchar_t	*start;
	size_t	nlen;

	nlen = ft_wstrlen(needle);
	if (!nlen)
		return ((wchar_t*)hstack);
	start = (wchar_t*)hstack;
	while ((start = ft_wstrchr(start, *needle)))
	{
		if (!ft_wstrncmp(start, needle, nlen))
			return (start);
		start++;
	}
	return (NULL);
}
