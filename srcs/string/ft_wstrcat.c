/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:28:08 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:47:28 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrcat(wchar_t *dest, const wchar_t *src)
{
	wchar_t	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*(ptr++) = *(src++);
	*ptr = 0;
	return (dest);
}
