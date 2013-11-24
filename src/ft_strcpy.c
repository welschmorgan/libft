/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:38:50 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 19:06:15 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(src);
	ret = ft_memcpy((void*)dest, (const void*)src, sizeof(char) * (len + 1));
	return (ret);
}
