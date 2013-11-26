#include "test.h"

int	ft_test_strequ2(char const *s1, char const *s2)
{
	int	res;
	int	res2;
	int	res3;

	res = 0;
	res2 = ft_strequ(s1, s2);
	res3 = (strcmp(s1, s2)) ? 0:1;
	if (res2 != res3)
		++res;
	printf("Test : Compare \"%s\" and \"%s\" { %d - %d }", s1, s2, res2, res3);
	ft_print_status(res);
	return (res);
}

int	ft_test_strnequ(char const *s1, char const *s2, int n)
{
	int	res;
	int	res2;
	int	res3;

	res = 0;
	res2 = ft_strnequ(s1, s2, n);
	res3 = (strncmp(s1, s2, n)) ? 0:1;
	if (res2 != res3)
		++res;
	printf("Test : Compare \"%s\" and \"%s\" (%d) { %d - %d }", s1, s2, n, res2, res3);
	ft_print_status(res);
	return (res);
}

int	ft_test_strequ(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strequ");
	res += ft_test_strequ2("Bonjour", "Bonjour");
	res += ft_test_strequ2("Bon", "bon");
	res += ft_test_strequ2("Bonjour", "Bon");
	res += ft_test_strequ2("", "");
	ft_print_end(res);
	ft_print_begin("ft_strnequ");
	res += ft_test_strnequ("Bonjour", "Bonjour", 3);
	res += ft_test_strnequ("Bon", "bon", 1);
	res += ft_test_strnequ("Bonjour", "Bon", 4);
	res += ft_test_strnequ("Bonjour", "Bon", 3);
	res += ft_test_strnequ("", "", 3);
	return (ft_print_end(res));
}