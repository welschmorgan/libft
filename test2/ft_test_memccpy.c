/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memccpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 07:50:36 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 08:51:28 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		ft_test_memccpy(void)
{
	int			res;
	t_memtest 	t1;
	t_memtest 	t2;
	void		*res2;
	void		*res3;

	t1.c = 'Y';
	t1.c3 = '{';
	t1.c2 = ',';
	t1.num2 = 0xFFFFFFFF;
	t1.c4 = 'm';
	res = 0;
	ft_print_begin("ft_memccpy");
	bzero((void *)&t2, sizeof(t_memtest));
	res2 = ft_memccpy((void *)&t2, (const void *)&t1, '{', sizeof(t_memtest));
	if (!(t2.c == t1.c && t2.c3 == t1.c3 &&
		 t2.c2 != t1.c2 && t2.num2 != t1.num2 && t2.c4 != t1.c4))
	{
		ft_print_error("An space memory is different");
		++res;
	}
	t2.c3 = 0;
	t2.c = 0;
	res3 = memccpy((void *)&t2, (const void *)&t1, '{', sizeof(t_memtest));
	if (res2 != res3)
	{
		printf("\033[31mError : \033[0m\"Result pointer is not valid { %p (your) - %p }\n", res2, res3);
		++res;
	}
	res2 = ft_memccpy((void *)&t2, (const void *)&t1, ',', sizeof(t_memtest));
	if (!(t2.c == t1.c && t2.c3 == t1.c3 &&
		 t2.c2 == t1.c2 && t2.num2 != t1.num2 && t2.c4 != t1.c4))
	{
		ft_print_error("An space memory is different");
		++res;
	}
	t2.c2 = 0;
	res3 = memccpy((void *)&t2, (const void *)&t1, ',', sizeof(t_memtest));
	if (res2 != res3)
	{
		printf("\033[31mError : \033[0m\"Result pointer is not valid { %p (your) - %p }\n", res2, res3);
		++res;
	}
	res2 = ft_memccpy((void *)&t2, (const void *)&t1, 'm', sizeof(t_memtest));
	if (!(t2.c == t1.c && t2.c3 == t1.c3 &&
		 t2.c2 == t1.c2 && t2.num2 == t1.num2 && t2.c4 == t1.c4))
	{
		ft_print_error("An space memory is different");
		++res;
	}
	t2.num2 = 0;
	res3 = memccpy((void *)&t2, (const void *)&t1, 'm', sizeof(t_memtest));
	if (res2 != res3)
	{
		printf("\033[31mError : \033[0m\"Result pointer is not valid { %p (your) - %p }\n", res2, res3);
		++res;
	}
	printf("Test");
	ft_print_status(res);
	return (ft_print_end(res));
}
