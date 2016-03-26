/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:11:31 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 11:01:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*start;
	const char	*end;
	const char	*cur;

	start = str;
	end = str + ft_strlen(str);
	cur = end;
	while (cur && cur >= start)
	{
		if (*cur == (char)c)
			return ((char*)cur);
		cur--;
	}
	return (NULL);
}
