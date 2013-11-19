/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:35:15 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/19 16:52:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char) * ft_strlen(src));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
