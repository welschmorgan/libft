#include "test.h"

int	ft_test_putchar2(char c)
{
	int		res;
	char	res2;
	int		fd;
	FILE	*fptr;
	ssize_t	nread;

	res = 0;
	fptr = freopen("log.txt","w",stdout);
	ft_putchar(c);
	fptr = freopen("/dev/tty","w",stdout);
	(void)fptr;
	fd = open("log.txt", O_RDONLY);
	nread = read(fd, &res2, 1);
	(void)nread;
	close(fd);
	if (res2 != c)
		++res;
	printf("Test : '%c' { '%c' }", c, res2);
	ft_print_status(res);
	return (res);
}

int	ft_test_putchar(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_putchar");
	res += ft_test_putchar2('t');
	res += ft_test_putchar2('\n');
	return (ft_print_end(res));
}