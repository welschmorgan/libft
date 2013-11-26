/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:53:40 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 14:40:57 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char*)str);
		str ++;
	}
	if (str && c == '\0' && *str == c)
		return ((char*)str);
	return (NULL);
}
