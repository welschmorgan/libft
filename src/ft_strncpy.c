#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = dest;
	while (i < n && src && *src)
	{
		dest[i] = src[i];
		i ++;
	}
	while (i < n && src)
	{
		dest[i] = '\0';
		i ++;
	}
	return (ptr);
}
