/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:29:00 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:45:09 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrncat(wchar_t *dest,
										 const wchar_t *src,
										 size_t n)
{
	wchar_t	*p_cur;

	p_cur = dest + ft_wstrlen(dest);
	while (n-- && *src)
		*(p_cur++) = *(src++);
	*p_cur = 0;
	return (dest);
}
