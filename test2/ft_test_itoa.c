#include "test.h"

int	ft_test_itoa2(int number, char const *final)
{
	int		res;
	char	*res2;

	res = 0;
	res2 = ft_itoa(number);
	if (!res2 && final)
		++res;
	if (res2)
	{
		if (strcmp(res2, final))
		{
			ft_print_error("Results strings are not equal");
			++res;
		}
	}
	printf("Test : %d { \"%s\" (your) - \"%s\" }", number, res2, final);
	ft_print_status(res);
	return (res);
}

int	ft_test_itoa(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_itoa");
	res += ft_test_itoa2(45, "45");
	res += ft_test_itoa2(0, "0");
	res += ft_test_itoa2(-45, "-45");
	res += ft_test_itoa2(-2147483648, "-2147483648");
	res += ft_test_itoa2(2147483647, "2147483647");
	res += ft_test_itoa2(-1, "-1");
	return (ft_print_end(res));
}