/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 14:51:07 by mwelsch           #+#    #+#             */
/*   Updated: 2016/04/30 14:51:15 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "libft.h"

long		ft_atol(const char *str)
{
	long	ret;
	long	sign;

	if (!*str)
		return (0);
	sign = 1;
	ret = 0;
	while (ft_isanyof(*str, " \v\t\f\r\n"))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && sign > 0)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (sign * ret);
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (sign * ret);
}
