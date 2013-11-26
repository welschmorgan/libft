#include "test.h"

int	ft_test_strncat2(char *s1, char const *s2, int n, size_t len_buf)
{
	int		res;
	char	*res2;
	char	*str2;

	res = 0;
	str2 = (char *)malloc(sizeof(char) * len_buf);
	strcpy(str2, s1);
	res2 = ft_strncat(s1, s2, n);
	if (res2 != s1)
		++res;
	strncat(str2, s2, n);
	if (strcmp(str2, s1))
		++res;
	printf("Test : { \"%s\" }", str2);
	free(str2);
	ft_print_status(res);
	return (res);
}

int	ft_test_strncat(void)
{
	int	res;
	char buff[100];

	buff[0] = 0;
	res = 0;
	ft_print_begin("ft_strncat");
	res += ft_test_strncat2(buff, "Hello", 5, 100);
	res += ft_test_strncat2(buff, " world !lllokfkwejfwe", 8, 100);
	res += ft_test_strncat2(buff, "wekofwoekfw", 0, 100);
	return (ft_print_end(res));
}