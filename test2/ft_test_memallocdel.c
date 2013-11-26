#include "test.h"

int	ft_test_memallocdel(void)
{
	int		res;
	void	*ptr;

	res = 0;
	ft_print_begin("ft_memalloc");
	ptr = ft_memalloc(1024);
	ft_print_end(res);
	ft_print_begin("ft_memdel");
	ft_memdel(&ptr);
	if (ptr)
		++res;
	return (ft_print_end(res));
}