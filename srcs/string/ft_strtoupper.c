/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:08:30 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/02 21:08:45 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtoupper(char *str)
{
	return  (ft_strntoupper(str, ft_strlen(str)));
}

char		*ft_strntoupper(char *str, size_t n)
{
	char	*sav;

	sav = str;
	while (str && *str && n--)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (sav);
}
