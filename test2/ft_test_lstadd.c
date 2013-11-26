#include "test.h"

int	ft_test_lstadd(void)
{
	int		res;
	t_list	*begin;
	t_list	*new;
	t_list	*new2;
	char	str[] = "Bonjour";
	char	str2[] = "Test";

	res = 0;
	begin = 0;
	ft_print_begin("ft_lstadd");
	new = (t_list*)malloc(sizeof(t_list));
	new->next = 0;
	new->content = (void *)str;
	new->content_size = strlen(str);
	ft_lstadd(&begin, new);
	if (begin != new)
		++res;
	else
	{
		new2 = (t_list*)malloc(sizeof(t_list));
		new2->next = 0;
		new2->content = (void *)str2;
		new2->content_size = strlen(str2);
		ft_lstadd(&begin, new2);
		if (!begin)
			++res;
		else if (begin != new2 || begin->next != new)
			++res;
	}
	printf("Test");
	ft_print_status(res);
	return (ft_print_end(res));
}