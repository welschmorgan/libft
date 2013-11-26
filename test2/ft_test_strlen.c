/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:58:04 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 10:02:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_test_strlen2(const char *str)
{
	int		res;
	size_t	res2;
	size_t	res3;

	res = 0;
	printf("Test : \"%s\"", str);
	res2 = ft_strlen(str);
	res3 = strlen(str);
	if (res2 != res3)
		++res;
	printf("{ %ld (your) - %ld }", res2, res3);
	ft_print_status(res);
	return (res);
}

int			ft_test_strlen(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strlen");
	res += ft_test_strlen2("hello world !");
	res += ft_test_strlen2("");
	return (ft_print_end(res));
}
