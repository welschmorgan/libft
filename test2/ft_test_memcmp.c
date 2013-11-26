/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:47:39 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 10:08:54 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_tmemcmp2(const void *mem1, const void *mem2, size_t n)
{
	int	res;
	int	res2;
	int	res3;

	res = 0;
	res2 = ft_memcmp(mem1, mem2, n);
	res3 = memcmp(mem1, mem2, n);
	if (res2 != res3)
		++res;
	printf("Test : { %d (your) - %d }", res2, res3);
	ft_print_status(res);
	return (res);
}

int		ft_test_memcmp(void)
{
	int	res;
	t_struct1 t1;
	t_struct1 t2;
	char	*buf;

	buf = "test";
	t1.m_str = t2.m_str = buf;
	t1.m_char = t2.m_char = 't';
	t1.m_int = t2.m_int = 8997;
	t1.m_pointer = (void *)879;
	t2.m_pointer = 0;
	res = 0;
	ft_print_begin("ft_memcmp");
	res += ft_tmemcmp2((const void *)&t1, (const void *)&t2, sizeof(t_struct1));
	t2.m_pointer = (void *)879;
	res += ft_tmemcmp2((const void *)&t1, (const void *)&t2, sizeof(t_struct1));
	return (ft_print_end(res));
}
