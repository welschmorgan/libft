/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 07:41:59 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 07:49:31 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_test_memcpy2(void *dest, const void *src, size_t len)
{
	int			res;
	char		*tmp;
	const char	*tmp2;

	tmp = (char *)dest;
	tmp2 = (const char *)src;
	res = 0;
	printf("Test");
	ft_memcpy(dest, src, len);
	while (len)
	{
		if (*tmp != *tmp2)
			++res;
		--len;
	}
	if (res)
		ft_print_error("An byte in dest is different of src");
	ft_print_status(res);
	return (res);
}

int			ft_test_memcpy(void)
{
	int	res;
	t_struct1 t1;
	t_struct1 t2;

	t1.m_str = "test";
	t1.m_char = 'q';
	t1.m_pointer = (void *)ft_test_memcpy;
	res = 0;
	ft_print_begin("ft_memcpy");
	ft_test_memcpy2((void *)&t2, (const void *)&t1, sizeof(t_struct1));
	return (ft_print_end(res));
}
