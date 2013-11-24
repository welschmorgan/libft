#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#if __WORDSIZE == 64
#define LMAX "2147483647L"
#else
#define LMAX "9223372036854775807L"
#endif

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
