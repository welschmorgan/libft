#include "libft.h"

void	 ft_striter(char *s, void (*f)(char *))
{
	while (s && *s)
		f(s++);
}
