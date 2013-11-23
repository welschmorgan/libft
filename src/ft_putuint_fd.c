/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:39:51 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:40:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint_fd(unsigned int num, int fd)
{
	if (num >= 10)
	{
		ft_putuint_fd(num / 10,fd);
		ft_putuint_fd(num % 10,fd);
	}
	else
		ft_putchar_fd('0' + num,fd);
}
