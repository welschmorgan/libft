/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strncpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:50:08 by amerle            #+#    #+#             */
/*   Updated: 2013/11/25 14:05:54 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_test_strncpy2(char *s1, const char *s2, size_t n)
{
	int		res;
	char	*str;

	res = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	ft_strncpy(s1, s2, n);
	strncpy(str, s2, n);
	if (memcmp(str, s1, n))
		++res;
	printf("Test");
	ft_print_status(res);
	return (res);
}

int			ft_test_strncpy(void)
{
	int		res;
	char	str[] = "bonjour tout le monde gerg egeh erg fr erg";

	res = 0;
	ft_print_begin("ft_strncpy");
	res += ft_test_strncpy2(str, "test", 4);
	res += ft_test_strncpy2(str, "jgjfgdjjdfgklsjdfgl", strlen("jgjfgdjjdfgklsjdfgl"));
	res += ft_test_strncpy2(str, "jgjfgdjjdfgklsjdfgl", sizeof(str) + 1);
	return (ft_print_end(res));
}
