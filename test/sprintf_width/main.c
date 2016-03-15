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
	return (0);
}
