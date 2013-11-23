/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:40:24 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:40:40 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong_fd(long num, int fd)
{
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putlong_fd(-num, fd);
		return ;
	}
	if (num >= 10)
	{
		ft_putlong_fd(fd, num / 10);
		ft_putlong_fd(fd, num % 10);
	}
	else
		ft_putchar_fd(fd, '0' + num);
}
