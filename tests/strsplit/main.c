#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	do_clear(char ***ar)
{
	while (ar && *ar && **ar)
	{
		free(**ar);
		(**ar) ++;
	}
	**ar = NULL;
	free(*ar);
	*ar = NULL;
}

void	do_print(char **ar)
{
	size_t		i;

	i = 0;
	while (ar && *ar)
	{
		printf("\t[%u]: %s\n", (unsigned int)i, *ar);
		(*ar) ++;
		i ++;
	}
}

void	do_split(char const *str, char sep)
{
	char		**ar;
	FILE		*stream = stdout;

	ar = ft_strsplit(str, sep);
	fprintf(stream, "Strsplit(%s) sep(%c):\n", str, sep);
	do_print(ar);
	do_clear(&ar);   
}

int	main(void)
{
	do_split("test test2", ' ');
	return (0);
}
