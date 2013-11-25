#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strdup"

char	*strdup(const char *s);

void	do_test(const char *b)
{
	char		*bufa, *bufb;

	bufa = ft_strdup(b ? b : "");
	bufb = strdup(b ? b : "");
	fprintf(((bufa && bufb && strcmp(bufa, bufb) == 0) ? stdout : stderr),
			"Duplicating %s:\tlibft: %s\tlibc: %s\n",
			b, bufa, bufb);
	if (bufa)
		ft_strdel(&bufa);
	if (bufb)
		ft_strdel(&bufb);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite");
	do_test("Serviettes");
	do_test("Se");
	do_test("");
	do_test(NULL);

	print_hr();
	return (0);
}
