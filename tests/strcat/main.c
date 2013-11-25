#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strcat"

void	do_test(char const *a, char const *b)
{
	FILE	*stream;
	char	*verif_buf;
	char	*verif_buf2;

	verif_buf = ft_strdup(a);
	verif_buf2 = ft_strdup(a);
	ft_strcat(verif_buf, b);
	strcat(verif_buf2, b);
	stream = strcmp(verif_buf, verif_buf2) == 0 ? stdout : stderr;
	fprintf(stream,
			"Catted %s to %s: libft: %s - libc: %s\n",
			b,
			a,
			verif_buf,
			verif_buf2);
	ft_strdel(&verif_buf);
	ft_strdel(&verif_buf2);
}

int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", "Molle");
	do_test("", "Molle");
	do_test("Bite", "");
	do_test("", "");

	print_hr();
	return (0);
}