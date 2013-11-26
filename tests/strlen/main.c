#include "libft.h"
#include "common.h"
#include <string.h>
#include <ctype.h>

#define FUNC_NAME "strlen"

void	do_test(char const *a)
{
	FILE	*stream;
	size_t	ra;
	size_t	rb;

	ra = ft_strlen(a);
	rb = strlen(a);
	stream = ra == rb ? stdout : stderr;
	fprintf(stream,
			"Len of '%s': libft: %i - libc: %i\n",
			a,
			(int)ra,
			(int)rb);
}

int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite");
	do_test("");

	print_hr();
	return (0);
}
