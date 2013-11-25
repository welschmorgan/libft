#include "libft.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FUNC_NAME "isascii"

int		isascii(int);
void	do_test(char n)
{
	int		a;
	int		b;
	FILE	*stream;

	a = ft_isascii(n);
	b = isascii(n) ? 1 : 0;
	stream = ((a == b) ? stdout : stderr);

	fprintf(stream, "\tlibft: %i - ", a);
	fprintf(stream, "libc: %i\n", b);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test('a');
	do_test('0');
	do_test(')');

	print_hr();
	return (0);
}
