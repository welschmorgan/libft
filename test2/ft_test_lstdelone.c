#include "test.h"


static char		g_is_delete;

static void	ft_test_lstdelone2_del(void *content, size_t content_size)
{
	char	*str;

	str = (char *)content;
	if (str && content_size == strlen(str))
		g_is_delete = 1;
}

int	ft_test_lstdelone(void)
{
	int		res;
	t_list	*elem;
	char	str[] = "Bonjour";

	res = 0;
	ft_print_begin("ft_lstdelone");
	elem = (t_list*)malloc(sizeof(t_list));
	elem->next = 0;
	elem->content = (void *)str;
	elem->content_size = strlen(str);
	g_is_delete = 0;
	ft_lstdelone(&elem, ft_test_lstdelone2_del);
	if (elem || !g_is_delete)
		++res;
	if (elem)
		free(elem);
	printf("Test");
	ft_print_status(res);
	return (ft_print_end(res));
}