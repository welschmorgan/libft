#include "test.h"

int	ft_test_strsplit2(char const *s, char c, char **final)
{
	int		res;
	char	**tab_res;

	res = 0;
	printf("Test : \"%s\" ('%c')\n", s, c);
	tab_res = ft_strsplit(s, c);
	if (!tab_res)
		++res;
	while (*final && *tab_res)
	{
		printf("\tCompare : \"%s\" - \"%s\"\n", *final, *tab_res);
		if (strcmp(*final, *tab_res))
			++res;
		++final;
		++tab_res;
	}
	if (*final || *tab_res)
		++res;
	printf("Status :");
	ft_print_status(res);
	return (res);
}

int	ft_test_strsplit(void)
{
	int		res;
	char	*test1[5] = { "Hello", "World ", " ", "!", 0 };
	char	*test2[1] = { 0 };
	char	*test3[2] = { "==========", 0 };

	res = 0;
	ft_print_begin("ft_strsplit");
	res += ft_test_strsplit2("****Hello***World * *!", '*', (char **)test1);
	res += ft_test_strsplit2("**********************", '*', (char **)test2);
	res += ft_test_strsplit2("==========", '*', (char **)test3);
	return (ft_print_end(res));
}