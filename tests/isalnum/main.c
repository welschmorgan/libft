#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	do_isalnum(char c)
{
	
	FILE		*strm;
	int			a = ft_isalnum(c);
	int			b = isalnum(c);

	strm = ((a == b) ? stdout : stderr);
	fprintf(strm, "Isalnum(%c):\n\tlibft: %i\n\tlibc: %i\n", c, a, b);
}

int	main(void)
{
	do_isalnum('@');
	do_isalnum('a');
	do_isalnum('0');
	do_isalnum('~');
	return (0);
}
