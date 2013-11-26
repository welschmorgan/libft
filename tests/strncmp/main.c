#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strncmp"

void	do_test(const char *a, const char *b, size_t max)
{
	int		ra, rb;

	ra = ft_strncmp(a, b, max);
	rb = ((a && b) ? strncmp(a, b, max) : 0);
	fprintf(ra == rb ? stdout : stderr,
			"Comparing %s with %s (max %i): libft: %i | libc: %i\n",
			a, b, (int)max, ra, rb);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", "Bite",2);
	do_test("Serviettes", "Torchons",20);
	do_test("Se", "",0);
	do_test("", "",20);
	do_test(NULL, NULL, 0);

	print_hr();
	return (0);
}
