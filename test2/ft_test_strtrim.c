#include "test.h"

int	ft_test_strtrim2(char const *s, char const *final)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_strtrim(s);
	if (!str && ft_strlen(final))
		++res;
	else if (str && strcmp(str, final))
		++res;
	printf("Test : Trim \"%s\" { \"%s\" }", s, str);
	free(str);
	ft_print_status(res);
	return (res);
}

int	ft_test_strtrim(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strtrim");
	res += ft_test_strtrim2("  \nWelcome !   \n\t\n\t\n", "Welcome !");
	res += ft_test_strtrim2("       ", "");
	res += ft_test_strtrim2("teerierginerngeringerge   \t", "teerierginerngeringerge");
	res += ft_test_strtrim2(" teerierginerngeringerge", "teerierginerngeringerge");
	res += ft_test_strtrim2("", "");
	return (ft_print_end(res));
}