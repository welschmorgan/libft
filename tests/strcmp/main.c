#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strcmp"

void	do_test(const char *a, const char *b)
{
	int		ra, rb;

	ra = ft_strcmp(a, b);
	rb = ((a && b) ? strcmp(a, b) : 0);
	fprintf(ra == rb ? stdout : stderr,
			"Comparing %s with %s:\n\tlibft: %i\n\tlibc: %i\n",
		   a, b, ra, rb);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", "Bite");
	do_test("Serviettes", "Torchons");
	do_test("Se", "");
	do_test("", "");
	do_test(NULL, NULL);

	print_hr();
	return (0);
}
