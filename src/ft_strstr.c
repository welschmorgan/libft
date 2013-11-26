/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:21:32 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 16:43:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(char const *a, char const *b)
{
	char	*ptr;

	ptr = (char*)a;
	if (!a || !b)
		return (NULL);
	while ((ptr = strchr(ptr, *b)))
	{
		if (ft_strncmp(ptr, b, ft_strlen(b)))
			return (ptr);
		ptr ++;
	}
	return (NULL);
}
