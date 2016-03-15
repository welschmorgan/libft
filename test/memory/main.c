# include "main.h"
# include <libft.h>

int		cleanup()
{
	if (g_buf)
		ft_memdel(&g_buf);
	return (0);
}

int		init()
{
	add_test("alloc", test_alloc);
	add_test("dealloc", test_dealloc);
	add_test("copy", test_copy);
	add_test("copy (overflow)", test_copy_overflow);
	add_test("set", test_set);
	return (0);
}
