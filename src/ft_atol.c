/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:22:10 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 18:42:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *str)
{
	long	ret;

	ret = 0;
	if (*str == '-')
		return (-1 * ft_atol(++str));

	while (str && *str)
	{
		if (*str < '0' || *str > '9')
			return (ret);
		ret = (ret * 10) + ((*str) - '0');
		str ++;
	}
	return (ret);
}
