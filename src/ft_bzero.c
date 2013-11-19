#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*ptr;

	counter = 0;
	ptr = (unsigned char *)s;
	while (ptr && counter < n)
	{
		*ptr = 0;
		ptr ++;
		counter ++;
	}
}
