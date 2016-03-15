#include "libft.h"

int		test(char *(*fn)(char *,
						 size_t const n,
						 char const),
			 char *str,
			 size_t const n,
			 char const c)
{
	char	*buf;

	ft_printf("pad(\"%s\", %d, '%c'):\n", str, n, c);
	buf = ft_strnew(n);
	ft_strncpy(buf, str, n);
	fn(buf, n, c);
	ft_printf("\t-> %s\n", buf);
	ft_strdel(&buf);
	return (0);
}
int		test_left()
{
	test(ft_strpad_l, "hello", 10, '-');
	return (0);
}

int		test_right()
{
	test(ft_strpad_r, "hello", 10, '-');
	return (0);
}

int		test_both()
{
	test(ft_strpad, "hello", 10, '-');
	return (0);
}
