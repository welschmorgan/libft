#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (!size)
		return (NULL);
	ptr = (char*)ft_memalloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (i <= size)
	{
		ptr[i] = '\0';
		i ++;;
	}
	return (ptr);
}
