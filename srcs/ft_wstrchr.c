/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:31:10 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:33:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrchr(const wchar_t *str, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_wstrlen(str);
	while (i <= len)
	{
		if (str[i] == (wchar_t)c)
			return ((wchar_t*)(str + i));
		i++;
	}
	return (NULL);
}
