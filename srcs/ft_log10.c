/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:45:21 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 10:47:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_log10				*ft_log10_table(void)
{
	static t_log10	table[10] = {
		{1000000000u, 9u},
		{100000000u, 8u},
		{10000000u, 7u},
		{1000000u, 6u},
		{100000u, 5u},
		{10000u, 4u},
		{1000u, 3u},
		{100u, 2u},
		{10u, 1u},
		{1u, 0u},
	};

	return (&table[0]);
}

unsigned int		ft_log10(unsigned int num)
{
	int				i;
	t_log10			*logs;

	i = 0;
	logs = ft_log10_table();
	while (i < 10)
	{
		if (num >= logs[i].level)
			return (logs[i].value);
		i++;
	}
	return (0u);
}
