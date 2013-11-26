#include "test.h"

int	ft_test_strsub2(char const *s1, unsigned int start, size_t len, char const *str_final)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_strsub(s1, start, len);
	if (str && strcmp(str, str_final))
		++res;
	else if (!str && len > 0)
		++res;
	printf("Test : Sub \"%s\" (%d, %ld) { \"%s\" }", s1, start, len, str);
	free(str);
	ft_print_status(res);
	return (res);
}

int	ft_test_strsub(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strsub");
	res += ft_test_strsub2("Bonjour", 2, 3, "njo");
	res += ft_test_strsub2("Bonjour", 0, 0, "");
	res += ft_test_strsub2("Bienvenue", 7, 2, "ue");
	return (ft_print_end(res));
}