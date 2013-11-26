#include "test.h"

static t_list	*ft_test_lstmap_map(t_list *elem)
{
	int	*ptr;

	if (elem)
	{
		ptr = (int *)elem->content;
		--(*ptr);
	}
	return (elem);
}

int	ft_test_lstmap(void)
{
	int		res;
	int		i1;
	int		i2;
	t_list	*elem;
	t_list	*elem2;
	t_list	*new_list;
	t_list	*new_list_next;

	res = 0;
	i1 = 150;
	i2 = -130;
	new_list = 0;
	new_list_next = 0;
	ft_print_begin("ft_lstmap");
	elem = (t_list*)malloc(sizeof(t_list));
	elem2 = (t_list*)malloc(sizeof(t_list));
	elem->next = elem2;
	elem->content = (void *)&i1;
	elem->content_size = elem2->content_size = sizeof(int);
	elem2->content = (void *)&i2;
	elem2->next = 0;
	new_list = ft_lstmap(elem, ft_test_lstmap_map);
	if (!new_list || !new_list->next)
	{
		++res;
		printf("bad alloc { %p - %p }\n", new_list, (new_list) ? new_list->next : 0);
	}
	else
	{
		new_list_next = new_list->next;
		if (new_list == elem || new_list_next == elem2 || i1 != 149 || i2 != -131)
			++res;
	}
	printf("Test");
	ft_print_status(res);
	return (ft_print_end(res));
}