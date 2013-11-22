#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*ptr;

	if (!size)
		return (NULL);
	ptr = (char*)ft_memalloc(size);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}
