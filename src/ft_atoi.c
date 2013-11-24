/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:22:10 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:53:13 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	ret;

	ret = 0;
	if (*str == '-')
		return (-1 * ft_atoi(++str));

	while (str && *str)
	{
		if (*str < '0' || *str > '9')
			return (ret);
		ret = (ret * 10) + ((*str) - '0');
		str ++;
	}
	return (ret);
}
