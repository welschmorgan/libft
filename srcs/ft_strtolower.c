/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:05:06 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/02 21:08:26 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtolower(char *str)
{
	return  (ft_strntolower(str, ft_strlen(str)));
}

char		*ft_strntolower(char *str, size_t n)
{
	char	*sav;

	sav = str;
	while (str && *str && n--)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (sav);
}
