#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	do_isalpha(char c)
{
	int			a = ft_isalpha(c);
	int			b = isalpha(c);

	fprintf(OUT_STREAM(a, b), "Isalpha(%c):\n\tlibft: %i\n\tlibc: %i\n", c, a, b);
}

int	main(void)
{
	do_isalpha('a');
	do_isalpha('0');
	do_isalpha('@');
	return (0);
}
