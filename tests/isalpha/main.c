#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	do_isalpha(char c)
{
	
	FILE		*strm;
	int			a = ft_isalpha(c);
	int			b = isalpha(c);

	strm = ((a == b) ? stdout : stderr);
	fprintf(strm, "Isalpha(%c):\n\tlibft: %s\n\tlibc: %s\n", c, a ? "true" : "false", b ? "true" : "false");
}

int	main(void)
{
	do_isalpha('a');
	do_isalpha('0');
	do_isalpha('@');
	return (0);
}
