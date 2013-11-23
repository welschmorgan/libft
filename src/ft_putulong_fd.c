/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:42:00 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:42:12 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putulong_fd(unsigned long num, int fd)
{
	if (num >= 10)
	{
		ft_putulong_fd(num / 10, fd);
		ft_putulong_fd(num % 10, fd);
	}
	else
		ft_putchar_fd('0' + num, fd);
}
