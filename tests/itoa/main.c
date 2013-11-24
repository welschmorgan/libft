#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define FUNC_NAME "itoa"

void	do_test(int n)
{
	char	*a;
	char	*b;
	FILE	*stream;

	printf("---------------------------\n");
	printf("Testing '%s':\n", FUNC_NAME);
	printf("---------------------------\n");

	a = ft_itoa(n);
	b = ft_strnew(64);
	stream = ((!strcmp(a, b)) ? stdout : stderr);

	fprintf(stream, "\tlibft: %s\n", a);
	fprintf(stream, "\tlibc: %s\n", b);

	ft_strdel(&a);
	ft_strdel(&b);
	printf("---------------------------\n");
}

#define IMAX 2147483647

int	main(void)
{
	do_test(IMAX);
	do_test(-IMAX);
	do_test(0);
	return (0);
}
