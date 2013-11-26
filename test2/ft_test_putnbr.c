#include "test.h"

int	ft_test_putnbr2(int number, char const *final)
{
	int		res;
	char	*res2;
	int		fd;
	size_t	len;
	FILE	*fptr;
	ssize_t	nread;

	res = 0;
	len = strlen(final);
	res2 = (char *)malloc(sizeof(char) * (len + 1));
	memset((void *)res2, 0, len + 1);
	fptr = freopen("log.txt","w",stdout);
	ft_putnbr(number);
	fptr = freopen("/dev/tty","w",stdout);
	fd = open("log.txt", O_RDONLY);
	nread = read(fd, res2, len);
	(void)fptr;
	(void)nread;
	close(fd);
	if (strcmp(res2, final))
		++res;
	printf("Test : %d { \"%s\" - \"%s\" }", number, res2, final);
	free(res2);
	ft_print_status(res);
	return (res);
}

int	ft_test_putnbr(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_putnbr");
	res += ft_test_putnbr2(0, "0");
	res += ft_test_putnbr2(15642, "15642");
	res += ft_test_putnbr2(-1000005, "-1000005");
	return (ft_print_end(res));
}