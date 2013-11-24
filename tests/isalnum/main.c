#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	do_isalnum(char c)
{
	int			a = ft_isalnum(c);
	int			b = isalnum(c);

	fprintf(OUT_STREAM(a, b), "Isalnum(%c):\n\tlibft: %d\n\tlibc: %d\n", c, a, b);
}

int	main(void)
{
	do_isalnum('@');
	do_isalnum('a');
	do_isalnum('0');
	do_isalnum('~');
	return (0);
}
