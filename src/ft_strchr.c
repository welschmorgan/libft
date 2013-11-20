/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:53:40 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 20:06:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	while (str && *str)
	{
		if (*str == (char)c)
			return (str);
		str ++;
	}
	return (NULL);
}


char	*ft_strrchr(char *str, int c)
{
	char	*ptr;

	ptr = str + (ft_strlen(str) - 1);
	while (str && *str
		   && ptr && *ptr
		   && (ptr != (str - 1)))
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr --;
	}
	return (NULL);
}
