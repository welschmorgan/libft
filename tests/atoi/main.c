#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#define IMAX "2147483647"

void	do_atoi(char *str)
{
	int a		= ft_atoi(str);
	int b		= atoi(str);
	FILE		*stream = ((a == b) ? stdout : stderr);;

	fprintf(stream, "Atoi(%s):\n\tlibft: %i\n\tlibc: %i\n", str, a, b);
}

int	main(void)
{
	do_atoi("");
	do_atoi("0");
	do_atoi(IMAX);
	do_atoi("-" IMAX);
	return (0);
}
