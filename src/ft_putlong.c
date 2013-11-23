/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:36:02 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:36:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(long num)
{
	if (num < 0)
	{
		ft_putchar('-');
		ft_putlong(-num);
		return ;
	}
	if (num >= 10)
	{
		ft_putlong(num / 10);
		ft_putlong(num % 10);
	}
	else
		ft_putchar('0' + num);
}
