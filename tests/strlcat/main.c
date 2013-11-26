#include "libft.h"
#include "common.h"
#include <string.h>
#include <ctype.h>

size_t strlcat(char *dest, const char *src, size_t size);
#define FUNC_NAME "strlcat"

void	do_test(char const *a, char const *b)
{
	char	*verif_buf;
	char	*verif_buf2;
	size_t	ra;
	size_t	rb;
	size_t	len;

	len = ft_strlen(a) + ft_strlen(b);
	verif_buf = ft_strnew(len);
	verif_buf2 = ft_strnew(len);
	ft_strncpy(verif_buf, a, len);
	strncpy(verif_buf2, a, len);
	ra = ft_strlcat(verif_buf, b, len);
	rb = ft_strlcat(verif_buf2, b, len);
	fprintf(((strcmp(verif_buf, verif_buf2) == 0) ? stdout : stderr),
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
