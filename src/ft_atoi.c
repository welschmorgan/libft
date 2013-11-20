/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:22:10 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 20:31:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	ret;
	int	mul;

	ret = 0;
	mul = ((str && *str == '-') ? -1 : 1);

	while (str && *str)
	{
		if (*str < '0' || *str > '9')
			return (ret * mul);
		ret = (ret * 10) + ((*str) - '0');
		str ++;
	}
	return (ret * mul);
}
