#include "test.h"

static char	ft_toupper2(char c)
{
	return (char)toupper((int)c);
}

static char	ft_toupper3(unsigned int i, char c)
{
	if (i < 10)
		return (ft_toupper2(c));
	else
		return (c);
}

int	ft_test_strmap2(char const *s, char (*f)(char))
{
	int		res;
	size_t	len;
	char	*save;
	size_t	i;
	char	*new;

	res = 0;
	i = 0;
	len = strlen(s);
	printf("Test : \"%s\"", s);
	save = strdup(s);
	new = ft_strmap(s, f);
	while (i < len)
	{
		if (new[i] != (char)toupper(save[i]))
			++res;
		++i;
	}
	printf(" { \"%s\" }", new);
	free(save);
	free(new);
	ft_print_status(res);
	return (res);
}

int	ft_test_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		res;
	size_t	len;
	char	*save;
	size_t	i;
	char	*new;

	res = 0;
	i = 0;
	len = strlen(s);
	printf("Test : \"%s\"", s);
	save = strdup(s);
	new = ft_strmapi(s, f);
	while (i < len)
	{
		if (i < 10 && new[i] != (char)toupper(save[i]))
			++res;
		else if (i >= 10 && new[i] != save[i])
			++res;
		++i;
	}
	printf(" { \"%s\" }", new);
	free(save);
	free(new);
	ft_print_status(res);
	return (res);
}

int	ft_test_strmap(void)
{
	int		res;
	char	str[] = "##WelCome in New world !##";
	char	str2[] = "";
	char	str3[] = "##WelCome in New world !##";

	res = 0;
	ft_print_begin("ft_strmap");
	res += ft_test_strmap2(str, ft_toupper2);
	res += ft_test_strmap2(str2, ft_toupper2);
	ft_print_end(res);
	ft_print_begin("ft_strmapi");
	res += ft_test_strmapi(str3, ft_toupper3);
	res += ft_test_strmapi(str2, ft_toupper3);
	return (ft_print_end(res));
}