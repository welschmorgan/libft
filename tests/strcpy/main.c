#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strcpy"

void	do_test(const char *b)
{
	char		*bufa, *bufb;

	bufa = ft_strnew(ft_strlen(b));
	bufb = ft_strnew(ft_strlen(b));
	if (b && bufa && bufb)
	{
		ft_strcpy(bufa, b);
		strcpy(bufb, b);
	}
	fprintf(((bufa && bufb && strcmp(bufa, bufb) == 0) ? stdout : stderr),
			"Copying %s to %p:\n\tlibft: %s\n\tlibc: %s\n",
			b, bufa, bufa, bufb);
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