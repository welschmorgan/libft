#include "libft.h"
#include <stdio.h>

int				print_array(char *data, size_t size)
{
	size_t	i = 0;

	while (i < size)
	{
		printf("\t%s\n", data[i]);
		i ++;
	}
}
int				main(void)
{
	int		i = 8;
	ft_memset(&i, 10, sizeof(int));
	printf("Memset: %i\n", i);
	return (0);
}
