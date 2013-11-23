/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:37:01 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:37:11 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putulong(unsigned long num)
{
	if (num >= 10)
	{
		ft_putulong(num / 10);
		ft_putulong(num % 10);
	}
	else
		ft_putchar('0' + num);
}
