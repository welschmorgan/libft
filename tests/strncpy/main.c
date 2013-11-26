#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strnpy"

void	do_test(char const *a, size_t max)
{
	FILE	*stream;
	char	*verif_buf;
	char	*verif_buf2;
	size_t	len;

	verif_buf = ft_strnew(len);
	verif_buf2 = ft_strnew(len);

	ft_strncpy(verif_buf, a);
	strncpy(verif_buf2);

	stream = strcmp(verif_buf, verif_buf2) == 0 ? stdout : stderr;

	fprintf(stream,
			"N-Copied %s to %s (max %i): libft: %s - libc: %s\n",
			b,
			a,
			(int)max,
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

	do_test("Bite", 2);
	do_test("", 5);
	do_test("Bite", 10);
	do_test("", "", 10);

	print_hr();
	return (0);
}
