#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	do_atol(char *str)
{
	int a		= ft_atol(str);
	int b		= atol(str);
	FILE		*stream = ((a == b) ? stdout : stderr);;

	fprintf(stream, "Atol(%s):\n\tlibft: %i\n\tlibc: %i\n", str, a, b);
}

int	main(void)
{
	do_atol("");
	do_atol("0");
	do_atol("-32767");
	do_atol("32767");
	do_atol("-32768");
	do_atol("32768");
	return (0);
}
