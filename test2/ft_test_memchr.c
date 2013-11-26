/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:07:45 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 09:46:21 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_test_memchr2(const void *src, int c, size_t len)
{
	int		res;
	void	*pres;
	void	*pres2;

	res = 0;
	pres = ft_memchr(src, c, len);
	pres2 = memchr(src, c, len);
	if (pres != pres2)
		++res;
	printf("Test : \"%s\" (%c - %ld) { %p (your) - %p }", (char const *)src, c, len, pres, pres2);
	ft_print_status(res);
	return (res);
}

int		ft_test_memchr(void)
{
	int		res;
	char	str[] = "Ceci est une chaine inutile{";

	res = 0;
	ft_print_begin("ft_memchr");
	res += ft_test_memchr2(str, 'u', strlen(str));
	res += ft_test_memchr2(str, 'z', strlen(str));
	res += ft_test_memchr2(str, '}', strlen(str));
	return (ft_print_end(res));
}
