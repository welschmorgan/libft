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
size_t	count_strsub(char const *start, char const *end)
{
	size_t	ret;

	ret = 0;
	while (start && start != end && *start)
	{
		ret ++;
		start ++;
	}
	return ret;
}
void	do_split(char const *str, char sep)
{
	char	*p_cur;
	char	*p_last;
	char	*tmp;
	size_t	i;

	p_last = (char*)str;
	tmp = NULL;
	i = 0;
	while ((p_cur = ft_strchr(p_last + 1, sep)))
	{
		printf("Found separator '%c' at %i\n", sep, (int)i);
		tmp = ft_strnew(count_strsub(p_last, p_cur));
		ft_putstr("word: ");
		ft_putendl(tmp);
		ft_strdel(&tmp);
		p_last = p_cur;
		i ++;
	}
}

int	main(void)
{
	do_split("test test2", ' ');
	return (0);
}
