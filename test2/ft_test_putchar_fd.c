#include "test.h"

int	ft_test_putchar_fd2(char c)
{
	int		res;
	char	res2;
	int		fd;
	ssize_t	nread;

	res = 0;
	fd = open("log.txt", O_WRONLY);
	ft_putchar_fd(c, fd);
	close(fd);
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

int	ft_test_putchar_fd(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_putchar_fd");
	res += ft_test_putchar_fd2('t');
	res += ft_test_putchar_fd2('\n');
	return (ft_print_end(res));
}