/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:19:20 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:26:12 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrcpy(wchar_t *dest, const wchar_t *src)
{
	wchar_t	*ptr;

	ptr = dest;
	while (ptr && *src)
		*(ptr++) = *(src++);
	*ptr = 0;
	return (dest);
}
