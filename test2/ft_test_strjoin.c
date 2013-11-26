#include "test.h"

int	ft_test_strjoin2(char const *s1, char const *s2, char const *final)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_strjoin(s1, s2);
	if (str && strcmp(str, final))
		++res;
	else if (!str && ft_strlen(s1) && ft_strlen(s2))
		++res;
	printf("Test : Join \"%s\" and \"%s\" { \"%s\" }", s1, s2, str);
	free(str);
	ft_print_status(res);
	return (res);
}

int	ft_test_strjoin(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_strjoin");
	res += ft_test_strjoin2("Bonjour", " tout le monde", "Bonjour tout le monde");
	res += ft_test_strjoin2("", "Hello", "Hello");
	res += ft_test_strjoin2("", "", "");
	res += ft_test_strjoin2("Hello", " world !", "Hello world !");
	return (ft_print_end(res));
}