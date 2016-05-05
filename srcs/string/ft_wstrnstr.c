/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:35:09 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:46:27 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrnstr(const wchar_t *hstack,
										 const wchar_t *needle,
										 size_t n)
{
	wchar_t	*start;
	wchar_t	*max;
	size_t	nlen;

	nlen = ft_wstrlen(needle);
	max = (wchar_t*)(hstack + n);
	if (!nlen)
		return ((wchar_t*)hstack);
	start = (wchar_t*)hstack;
	while ((start = ft_wstrchr(start, *needle)) && start <= max)
	{
		if (start + nlen <= max && !ft_wstrncmp(start, needle, nlen))
			return (start);
		start++;
	}
	return (NULL);
}
