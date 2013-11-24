#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	ft_strncpy(dest + len, src, (len > n ? n : len));
	return (dest);
}
