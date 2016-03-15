# include "main.h"

char	buffer[255] = {0};
int		ret = 0;

int		cleanup()
{
	return (0);
}

int		init()
{
	add_test("sprintf<string>", test_strings);
	add_test("sprintf<bool>", test_booleans);
	add_test("sprintf<number>", test_numbers);
	add_test("sprintf<hexa>", test_hexadecs);
	add_test("sprintf<pointer>", test_pointers);

	add_test("sprintf<string width>", test_strings_w);
	return (0);
}
