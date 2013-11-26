#include "test.h"

int	ft_test_strnstr2(char const *s1, char const *s2, int n)
{
	int		res;
	char	*res2;
	char	*res3;

	res = 0;
	res2 = ft_strnstr(s1, s2, n);
	res3 = strnstr(s1, s2, n);
	if (res2 != res3)
		++res;
	printf("Test : Compare \"%s\" and \"%s\" (%d) { %p - %p }", s1, s2, n, res2, res3);
	ft_print_status(res);
	return (res);
}

int	ft_test_strnstr(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strnstr");
	res += ft_test_strnstr2("tvaaabcd", "aabc", 4);
	res += ft_test_strnstr2("tvaaabcd", "aabc", 8);
	res += ft_test_strnstr2("", "", 5);
	res += ft_test_strnstr2("", "e", 1);
	res += ft_test_strnstr2("Bonjour", "Bonjour", 7);
	res += ft_test_strnstr2("Bonjour", "bonjour", 7);
	return (ft_print_end(res));
}