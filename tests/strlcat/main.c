#include "libft.h"
#include "common.h"
#include <string.h>
#include <ctype.h>

size_t strlcat(char *dest, const char *src, size_t size);
#define FUNC_NAME "strlcat"

void	do_test(char const *a, char const *b)
{
	FILE	*stream;
	char	*verif_buf;
	char	*verif_buf2;
	size_t	ra;
	size_t	rb;

	verif_buf = ft_strdup(a);
	verif_buf2 = ft_strdup(a);
	ra = ft_strlcat(verif_buf, b, ft_strlen(b));
	rb = ft_strlcat(verif_buf2, b, ft_strlen(b));
	stream = strcmp(verif_buf, verif_buf2) == 0 ? stdout : stderr;
	fprintf(stream,
			"LCatted %s to %s: libft: %i - libc: %i\n",
			b,
			a,
			(int)ra,
			(int)rb);
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
