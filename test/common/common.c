/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:21:59 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 20:13:06 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_dlist			g_tests;
t_test const	*g_test = NULL;

t_row			g_row;
int const		g_row_sizes[CELL_COUNT] = {
	21,
	12,
	15,
	16,
	17,
	6
};

char	const	*g_row_names[CELL_COUNT][CELL_LENGTH_MAX] = {
	{"GROUP"},
	{"NAME"},
	{"INPUT"},
	{"LIBC"},
	{"LIBFT"},
	{"STATUS"}
};


int		main()
{
	t_dnode				*cur;
	int					ret;

	ft_dlist_init(&g_tests);
	ft_row_init(&g_row, 6, g_row_sizes, (char const **)g_row_names);
	print_separator();
	ft_row_print_header(&g_row, 1);
	init();
	cur = g_tests.tail;
	while (cur)
	{
		g_test = (t_test*)cur->data;
		ret = start_test(g_test);
		if (ret)
			return (ret);
		cur = cur->next;
	}
	cleanup();
	ft_row_reset(&g_row);
	ft_dlist_clear(&g_tests, NULL);
	return (0);
}
