/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:36:30 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:37:15 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint(unsigned int num)
{
	if (num >= 10)
	{
		ft_putuint(num / 10);
		ft_putuint(num % 10);
	}
	else
		ft_putchar('0' + num);
}
