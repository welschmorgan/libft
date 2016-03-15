#include "main.h"

#include <libft.h>

int		print_node(t_dlist_iter *it)
{
	ft_printf("node[%d]: %s\n",
			  it->id,
			  (char*)ft_dlist_iter_data(it));
	return (0);
}

int		test_add()
{
	char const	*str[] =
		{
			"hello biatch 1",
			"hello biatch 2",
			"hello biatch 3",
			"hello biatch 4",
			"hello biatch 5",
		};
	ft_dlist_add_back_str(&g_list, ft_strdup(str[0]), NF_DESTROY_ALL);
	ft_dlist_add_back_str(&g_list, ft_strdup(str[1]), NF_DESTROY_ALL);
	ft_dlist_add_back_str(&g_list, ft_strdup(str[2]), NF_DESTROY_ALL);
	ft_dlist_add_back_str(&g_list, ft_strdup(str[3]), NF_DESTROY_ALL);
	ft_dlist_add_back_str(&g_list, ft_strdup(str[4]), NF_DESTROY_ALL);
	ft_dlist_iterate(&g_list, print_node);
	return (0);
}

int		test_remfirst()
{
	ft_dlist_remove(&g_list, &g_list.tail, ft_dlist_deleter);
	ft_dlist_iterate(&g_list, print_node);
	return (0);
}

int		test_clear()
{
	ft_dlist_clear(&g_list, ft_dlist_deleter);
	ft_dlist_iterate(&g_list, print_node);
	return (0);
}
