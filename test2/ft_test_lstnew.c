#include "test.h"

int	ft_test_lstnew(void)
{
	t_list	*elem;
	int		res;
	char	str[] = "Welcome";

	res = 0;
	ft_print_begin("ft_lstnew");
	elem = ft_lstnew((void const *)str, sizeof(str));
	printf("Test");
	if (!elem)
	{
		ft_print_error("Not valid pointer return");
		++res;
	}
	else if (elem->content != (void *)str ||
			 elem->content_size != sizeof(str) ||
			 elem->next != 0)
	{
		if (memcmp(elem->content, (const void *)str, sizeof(str)))
		{
			ft_print_error("Not valid data in new element");
			++res;
		}
		//ft_print_warning("Valid data in element but in a new memory location");
		++res;
	}
	ft_print_status(res);
	return (ft_print_end(res));
}