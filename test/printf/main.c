# include "main.h"

int		cleanup()
{
	return (0);
}

int		init()
{
	add_test("%b", test_booleans);
	add_test("%b", test_numbers);
	add_test("%x", test_hexadecs);
	add_test("%p", test_pointers );
	return (0);
}
