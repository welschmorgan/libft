/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:11:31 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/24 22:11:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*ptr;

	ptr = str + (ft_strlen(str) - 1);
	while (ptr && *ptr
		   && (ptr != (str - 1)))
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr --;
	}
	return (NULL);
}
