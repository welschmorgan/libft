# include "main.h"
# include <libft.h>

int		init()
{
	add_test("pad left", test_left);
	add_test("pad right", test_right);
	add_test("pad both", test_both);
	return (0);
}

int		cleanup()
{
	return (0);
}
