#include "test.h"

static int	ft_test_strncmp2(char const *s1, char const *s2, int n)
{
	int	res;
	int	res2;
	int	res3;

	res = 0;
	res2 = ft_strncmp(s1, s2, n);
	res3 = strncmp(s1, s2, n);
	if (res2 != res3)
		++res;
	printf("Test : Compare \"%s\" and \"%s\" (%d) { %d - %d }", s1, s2, n, res2, res3);
	ft_print_status(res);
	return (res);
}

int	ft_test_strncmp(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strncmp");
	res += ft_test_strncmp2("Zelcome", "Welcome", 1);
	res += ft_test_strncmp2("Welcome", "welcome", 7);
	res += ft_test_strncmp2("Hello", "", 6);
	res += ft_test_strncmp2("", "", 0);
	res += ft_test_strncmp2("bonjour", "bonjour", 7);
	res += ft_test_strncmp2("bonjour", "bonjour", 8);
	res += ft_test_strncmp2("bonjour", "bonjour", 100);
	res += ft_test_strncmp2("cba", "abc", 2);
	return (ft_print_end(res));
}