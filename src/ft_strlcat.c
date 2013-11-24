#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if ((slen + dlen) >= size)
		return (slen + dlen);
	ft_strncpy(dest + dlen, src, slen);
	return (dlen + slen);
}
