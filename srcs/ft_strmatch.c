/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:13:34 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:08:40 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool				ft_strmatch(const char *str, const char *pattern)
{
	if (!*str && !*pattern)
		return (TRUE);
	if (*str == *pattern)
		return (ft_strmatch(str + 1, pattern + 1));
	else if (*pattern == '*')
	{
		if (*(pattern + 1) == *(str + 1))
			return (ft_strmatch(str + 1, pattern + 1));
		else
			return (ft_strmatch(str + 1, pattern));
	}
	return (FALSE);
}
