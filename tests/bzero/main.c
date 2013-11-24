#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void	do_bzero(size_t size)
{
	int			*ar0, *ar1;
	size_t		i = 0;

	ar0 = (int *)ft_memalloc(sizeof(int) * size);
	ar1 = (int *)ft_memalloc(sizeof(int) * size);
	if (!ar0)
		fprintf(stderr, "Bzero: invalid malloc\n");
	if (!ar1)
		fprintf(stderr, "Bzero: invalid malloc\n");
	ft_bzero(ar0, size);
	bzero(ar1, size);
	fprintf(stdout, "Bzero(size %i):\n\tlibft: ", (int)size);
	while (i < size)
	{
		fprintf(stdout, "%i%s", ar0[i], ((i!=(size-1)) ? "," : ""));
		i ++;
	}
	fprintf(stdout, "\n\tlibc: ");
	i = 0;
	while (i < size)
	{
		fprintf(stdout, "%i%s", ar1[i], ((i!=(size-1)) ? "," : ""));
		i ++;
	}
	ft_memdel((void**)&ar0);
	ft_memdel((void**)&ar1);
	fprintf(stdout, "\n");
}

int	main(void)
{
	do_bzero(1);
	do_bzero(0);
	do_bzero(10);
	return (0);
}
