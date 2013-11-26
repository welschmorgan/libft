#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strnstr"

char	*do_strnstr(char const *a, char const *b, size_t n)
{
	char	*ptr;

	ptr = (char*)a;
	if (!a || !b)
		return (NULL);
	while ((ptr = strchr(ptr, *b)))
	{
		if (ft_strncmp(ptr, b, n))
			return (ptr);
		ptr ++;
	}
	return (NULL);
}
void	do_test(char const *a, char const *b, size_t n)
{
	printf("Searching for %s in %s:\n\tlibft: %s\n\tlibc: %s\n",
		   b,
		   a,
		   do_strnstr(a, b, n),
		   a && b ? strnstr(a, b, n) : NULL);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", "Bite", 4);
	do_test("Bite", "Bite", 1);
	do_test("Bite", "Bite", 100);
	do_test("hello world", "", 15);
	do_test(NULL, " ", 1);
	do_test("", " ", 1);
	do_test("blah", " ", 1);

	print_hr();
	return (0);
}
