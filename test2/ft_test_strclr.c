#include "test.h"

int	ft_test_strclr2(char *s)
{
	int		res;
	size_t	len;

	res = 0;
	printf("Test : \"%s\"", s);
	len = strlen(s);
	ft_strclr(s);
	while (len)
	{
		if (*s)
			++res;
		--len;
	}
	ft_print_status(res);
	return (res);
}

int ft_test_strclr(void)
{
	int		res;
	char	str[] = "Welcome !";
	char	str2[] = "";

	res = 0;
	ft_print_begin("ft_strclr");
	res += ft_test_strclr2(str);
	res += ft_test_strclr2(str2);
	return (ft_print_end(res));
}