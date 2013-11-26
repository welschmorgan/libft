#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strstr"

char	*do_strstr(char const *a, char const *b)
{
	char	*ptr;

	ptr = (char*)a;
	if (!a || !b)
		return (NULL);
	while ((ptr = strchr(ptr, *b)))
	{
		if (ft_strncmp(ptr, b, ft_strlen(b)))
			return (ptr);
		printf("%s found in %s at %s\n", b, a, ptr);
		ptr ++;
	}
	return (NULL);
}
void	do_test(char const *a, char const *b)
{
	printf("Searching for %s in %s:\n\tlibft: %s\n\tlibc: %s\n",
		   b,
		   a,
		   do_strstr(a, b),
		   a && b ? strstr(a, b) : NULL);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", "t");
	do_test("hello world", " ");
	do_test(NULL, " ");
	do_test("", " ");
	do_test("blah", " ");

	print_hr();
	return (0);
}
