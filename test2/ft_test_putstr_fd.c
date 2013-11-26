#include "test.h"

int	ft_test_putstr_fd2(char const *str)
{
	int		res;
	char	*res2;
	int		fd;
	size_t	len;
	ssize_t	nread;

	res = 0;
	len = strlen(str);
	res2 = (char *)malloc(sizeof(char) * (len + 1));
	memset((void *)res2, 0, len + 1);
	fd = open("log.txt", O_WRONLY);
	ft_putstr_fd(str, fd);
	close(fd);
	fd = open("log.txt", O_RDONLY);
	nread = read(fd, res2, len);
	(void)nread;
	close(fd);
	if (strcmp(res2, str))
		++res;
	printf("Test : \"%s\" { \"%s\" }", str, res2);
	free(res2);
	ft_print_status(res);
	return (res);
}

int	ft_test_putstr_fd(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_putstr_fd");
	res += ft_test_putstr_fd2("Hello world !");
	res += ft_test_putstr_fd2("Welcome\nIt's a test\n");
	return (ft_print_end(res));
}