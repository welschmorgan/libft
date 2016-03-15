/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:02:56 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 19:51:13 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "libft_memory.h"

t_test const	*current_test()
{
	return (g_test);
}

t_test	*new_test(char const *name, int (*func)())
{
	t_test		*t;

	t = ft_memalloc(sizeof(t_test));
	ft_strncpy(t->name, name, 20);
	t->func = func;
	return (t);
}

void	reset_test(t_test *t)
{
	if (!t)
		return ;
	t_dnode	*cur;
	t_row	*row;

	cur = t->rows.tail;
	while (cur)
	{
		row = (t_row*)cur->data;
		ft_row_reset(row);
		cur++;
	}
	ft_dlist_clear(&t->rows, NULL);
}


t_row	*add_test_row(t_test *t, t_row const *r)
{
	t_row	*dup;

	if (!t)
		return (NULL);
	if (!r)
		return (NULL);
	dup = (t_row*)ft_memalloc(sizeof(t_row));
	ft_row_init(dup, r->ncols, r->sizes, (char const **)r->names);
	ft_dlist_add_back(&t->rows, ft_dnode_new(dup,
											 sizeof(t_row),
											 NF_DESTROY_ALL));
	return (dup);
}

t_test	*add_test(char const *name, int (*func)())
{
	t_test	*t;
	t = new_test(name, func);
	ft_dlist_add_back(&g_tests, ft_dnode_new(t,
											 sizeof(t_test),
											 NF_DESTROY_ALL));
	return (t);
}

void	print_separator()
{
	int		ret;

	ret = ft_row_length(&g_row);
	while (--ret)
		ft_putstr("-");
	ft_putendl(g_row.sep);
}

int		start_test(t_test const *test)
{
	int		ret;

	print_separator();
	ft_row_clear(&g_row);
	ft_row_set(&g_row, 0, test->name);
	ft_row_print(&g_row, 1);
	print_separator();
	ft_row_clear(&g_row);
	ret = test->func();
	return (ret);
}


void	print_result(int res)
{
	ft_row_set(&g_row, 5, res == 0 ? "OK" : "FAIL");
	ft_row_print(&g_row, 1);
}
