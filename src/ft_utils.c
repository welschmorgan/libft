/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:43:22 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 20:45:51 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putendl(char const *str)
{
	ft_putstr(str);
	ft_putstr("\n");
}
void	ft_putstr(char const *str)
{
	if (!str)
		write(1, INVALID_STR, ft_strlen(INVALID_STR));
	else
		write(1, str, ft_strlen(str));
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(-num);
		return ;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar('0' + num);
}

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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}

void	ft_putstr_fd(char const *str, int fd)
{
	if (!str)
		write(fd, INVALID_STR, ft_strlen(INVALID_STR));
	else
		write(fd, str, ft_strlen(str));
}

void	ft_putnbr_fd(int num, int fd)
{
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd('0' + num, fd);
}

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
