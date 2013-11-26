#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_cur;

	p_cur = dest + ft_strlen(dest);
	while (n -- && p_cur && src && *src)
		*(p_cur ++) = *(src ++);
	*p_cur = '\0';
	return (dest);
}
