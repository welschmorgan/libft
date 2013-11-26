/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 07:39:45 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 02:04:27 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int 	ft_test_strcmp2(char *str, char *str2)
{
	int	res;
	int	res2;
	int	res3;

	res = 0;
	res2 = ft_strcmp(str, str2);
	res3 = strcmp(str, str2);
	printf("Compare \"%s\" and \"%s\" { %d (your) , %d }", str, str2, res2, res3);
	if (res2 != res3)
		++res;
	ft_print_status(res2 != res3);
	return (res);
}

int			ft_test_strcmp(void)
{
	int 	res;
	char	str[] = "cba";
	char	str2[] = "abc";	

	res = 0;
	ft_print_begin("ft_strcmp");
	res += ft_test_strcmp2("test", "testing");
	res += ft_test_strcmp2(str, str2);
	res += ft_test_strcmp2("bonjour", "");
	res += ft_test_strcmp2("hello", "hello");
	res += ft_test_strcmp2("", "");
	res += ft_test_strcmp2(" ", ".");
	return (ft_print_end(res));
}
