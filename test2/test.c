/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 06:51:52 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 07:38:44 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	const	*ft_name_func;

void		ft_segfault(int c)
{
	(void)c;
	printf("\n\033[31mAn segfault is appear in test of : \033[0m\"%s\"\n", ft_name_func);
	exit(1);
}

void		ft_buserror(int c)
{
	(void)c;
	printf("\n\033[31mAn buserror is appear in test of : \033[0m\"%s\"\n", ft_name_func);
	exit(1);
}

void		ft_print_warning(char const *s)
{
	printf("\033[33mWarning : \033[0m\"%s\"\n", s);
}

void		ft_print_error(char const *s)
{
	printf("\033[31mError : \033[0m\"%s\"\n", s);
}

void		ft_print_status(int res)
{
	if (!res)
	{
		printf(" \033[32m[Success]\033[0m\n");
		++g_tests_ok;
	}
	else
		printf(" \033[31m[Fail]\033[0m\n");
	++g_tests;
}

void		ft_print_begin(const char *name)
{
	printf("\nBegin unit test : \033[34m%s\033[0m\n", name);
	ft_name_func = name;
}

int			ft_print_end(int res)
{
	ft_name_func = 0;
	printf("End unit test :");
	ft_print_status(res);
	return (res);
}
