/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:11:31 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 16:01:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*ptr;

	ptr = str + (ft_strlen(str) - 1);
	while (ptr && *ptr
		   && (ptr != (str - 1)))
	{
		if (*ptr == (char)c)
			return ((char*)ptr);
		ptr --;
	}
	return (NULL);
}
