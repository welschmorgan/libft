#include "test.h"

int	ft_test_isprint2(char c)
{
	int	res;
	int	res2;
	int	res3;

	res = 0;
	res2 = ft_isprint(c);
	res3 = isprint(c);
	if (res2 != res3)
		++res;
	if (res)
	{
		printf("Test : %c { %d (your) - %d }", c, res2, res3);
		ft_print_status(res);
	}
	return (res);
}

int	ft_test_isprint(void)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	ft_print_begin("ft_isprint");
	while (i++ < 255)
		res += ft_test_isprint2((char)i);
	return (ft_print_end(res));
}