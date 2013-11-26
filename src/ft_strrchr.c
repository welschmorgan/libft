/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:11:31 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 19:38:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*start;
	const char	*end;
	const char	*cur;

	start = str;
	if (!str)
		return ((char*)str);
	end = str + (ft_strlen(str) ? ft_strlen(str) : 0);
	cur = end;
	while (cur && cur >= start)
	{
		if (*cur == (char)c)
			return ((char*)cur);
		cur --;
	}
	return (NULL);
}
