#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#define FUNC_NAME "isdigit"

void	do_test(char n)
{
	int		a;
	int		b;
	FILE	*stream;

	printf("---------------------------\n");
	printf("Testing '%s':\n", FUNC_NAME);
	printf("---------------------------\n");

	a = ft_isdigit(n);
	b = isdigit(n) ? 1 : 0;
	stream = ((a == b) ? stdout : stderr);

	fprintf(stream, "\tlibft: %i\n", a);
	fprintf(stream, "\tlibc: %i\n", b);

	printf("---------------------------\n");
}


int	main(void)
{
	do_test('a');
	do_test('0');
	do_test(')');
	return (0);
}
