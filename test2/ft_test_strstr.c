#include "test.h"

int	ft_test_strstr2(char const *s1, char const *s2)
{
	int		res;
	char	*res2;
	char	*res3;

	res = 0;
	res2 = ft_strstr(s1, s2);
	res3 = strstr(s1, s2);
	if (res2 != res3)
		++res;
	printf("Test : Compare \"%s\" and \"%s\" { %p - %p }", s1, s2, res2, res3);
	ft_print_status(res);
	return (res);
}

int	ft_test_strstr(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strstr");
	res += ft_test_strstr2("Welcome !", "come");
	res += ft_test_strstr2("Bonjour", "Bonjour ");
	res += ft_test_strstr2("bonjour", "");
	res += ft_test_strstr2("bonjour", "r\0");
	return (ft_print_end(res));
}