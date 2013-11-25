#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*ptr;

	ptr = (char*)ft_memalloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ft_strclr(ptr);
	return (ptr);
}
