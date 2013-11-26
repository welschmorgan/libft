/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:11:23 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 10:17:35 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_test_strdup2(const char *str)
{
	int		res;
	char	*cpy;
	char	*cpy2;

	res = 0;
	printf("Test : \"%s\"", str);
	cpy = ft_strdup(str);
	cpy2 = strdup(str);
	if (cpy == str)
	{
		ft_print_error("Not a new string");
		++res;
	}
	if (strcmp(cpy, cpy2))
		++res;
	printf("{ \"%s\" (your) - \"%s\" }", cpy, cpy2);
	ft_print_status(res);
	return (res);
}

int			ft_test_strdup(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strdup");
	res += ft_test_strdup2("Hello world !");
	res += ft_test_strdup2("");
	return (ft_print_end(res));
}
