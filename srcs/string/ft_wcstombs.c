/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:48:48 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 20:54:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t						ft_wcstombs(char *dest,
										wchar_t const *src,
										size_t n)
{
	size_t					len;
	size_t					next;
	char const				*mbs;

	len = 0;
	while (src && *src && n--)
	{
		mbs = ft_wctomb(*src);
		next = ft_strlen(mbs);
		if (dest)
			ft_strncpy(dest, mbs, next);
		len += next;
		src++;
	}
	return (len);
}
