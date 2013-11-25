#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strchr"

void	do_test(char *a, char c)
{
	printf("Searching for %c in %s:\n\tlibft: %s\n\tlibc: %s\n",
		   c,
		   a ? a : "NULL",
		   ft_strchr(a, c),
		   a ? strchr(a, c) : NULL);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", 't');
	do_test("hello world", ' ');
	do_test(NULL, ' ');
	do_test("", ' ');
	do_test("blah", ' ');

	print_hr();
	return (0);
}
