/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:26:14 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 10:59:10 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_cur;

	p_cur = dest + ft_strlen(dest);
	while (n-- && *src)
		*(p_cur++) = *(src++);
	*p_cur = '\0';
	return (dest);
}
