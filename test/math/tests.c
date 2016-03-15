/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch </var/mail/mwelsch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:18:55 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 20:04:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "common.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

int		test_pow_(float x, int p)
{
	double	a, b;
	int		ret;

	a = pow(x, p);
	b = ft_pow(x, p);
	ret = !(b > (a - FT_FLOAT_TOLERANCE) && b < (a + FT_FLOAT_TOLERANCE));
	ft_row_set(&g_row, NAME_CELL, "pow");
	ft_row_setf(&g_row, INPUT_CELL, "%f^%d", x, p);
	ft_row_setf(&g_row, LIBC_CELL, "%f", a);
	ft_row_setf(&g_row, LIBFT_CELL, "%f", b);
	ft_row_setf(&g_row, STATUS_CELL, "%s", ret == 0 ? "OK" : "FAIL");
	ft_row_print(&g_row, 1);
	return (ret);
}

int		test_log10_(unsigned n)
{
	unsigned	a, b;
	int			ret;

	a = log10(n);
	b = ft_log10(n);
	ret = !(b > (a - FT_FLOAT_TOLERANCE) && b < (a + FT_FLOAT_TOLERANCE));
	ft_row_set(&g_row, NAME_CELL, "log10");
	ft_row_setf(&g_row, INPUT_CELL, "%u", n);
	ft_row_setf(&g_row, LIBC_CELL, "%u", a);
	ft_row_setf(&g_row, LIBFT_CELL, "%u", b);
	ft_row_setf(&g_row, STATUS_CELL, "%s", ret == 0 ? "OK" : "FAIL");
	ft_row_print(&g_row, 1);
	return (ret);
}

int		test_log10()
{
	test_log10_(0);
	test_log10_(10);
	test_log10_(100);
	test_log10_(1000);
	test_log10_(10000);
	test_log10_(100000);
	test_log10_(1000000);
	return (0);
}

int		test_pow()
{
	test_pow_(0, 0);
	test_pow_(1, 1);
	test_pow_(1, 0);
	test_pow_(10, 1);
	test_pow_(10, 2);
	test_pow_(10, 3);
	test_pow_(10, 4);
	test_pow_(10, 5);
	return (0);
}
