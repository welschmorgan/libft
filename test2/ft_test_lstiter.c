#include "test.h"

static void	ft_test_lstiter_iter(t_list *elem)
{
	int	*ptr;

	if (elem)
	{
		ptr = (int *)elem->content;
		++(*ptr);
	}
}

int	ft_test_lstiter(void)
{
	int		res;
	int		i1;
	int		i2;
	t_list	*elem;
	t_list	*elem2;

	res = 0;
	i1 = 150;
	i2 = -130;
	ft_print_begin("ft_lstiter");
	elem = (t_list*)malloc(sizeof(t_list));
	elem2 = (t_list*)malloc(sizeof(t_list));
	elem->next = elem2;
	elem->content = (void *)&i1;
	elem->content_size = elem2->content_size = sizeof(int);
	elem2->content = (void *)&i2;
	elem2->next = 0;
	ft_lstiter(elem, ft_test_lstiter_iter);
	if (i1 != 151 || i2 != -129)
		++res;
	printf("Test");
	ft_print_status(res);
	return (ft_print_end(res));
}