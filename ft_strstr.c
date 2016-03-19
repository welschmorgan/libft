/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:21:32 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 12:01:10 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *hstack, char const *needle)
{
	char	*start;
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (!needle || !nlen || !hstack)
		return ((char*)hstack);
	start = (char*)hstack;
	while ((start = ft_strchr(start, *needle)))
	{
		if (!ft_strncmp(start, needle, nlen))
			return (start);
		start++;
	}
	return (NULL);
}
