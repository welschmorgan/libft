#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "isprint"

void	do_test(char n)
{
	int		a;
	int		b;
	FILE	*stream;

	a = ft_isprint(n);
	b = isprint(n) ? 1 : 0;
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
	do_test(')');

	print_hr();
	return (0);
}
