#include "main.h"

t_dlist	g_list;

int		init()
{
	add_test("add_bulk", test_add);
	add_test("remove_first", test_remfirst);
	add_test("remove_first", test_remfirst);
	add_test("clear", test_clear);

	ft_dlist_init(&g_list);

	return (0);
}

int		cleanup()
{
	ft_dlist_clear(&g_list, ft_dlist_deleter);
	return (0);
}
