#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;
	t_bool	eol;

	ptr = dest;
	eol = FALSE;
	while (ptr && *ptr && src && n--)
	{
		if (*src == '\0')
			eol = TRUE;
		if (eol)
			*(ptr++) = '\0';
		else
			*(ptr++) = *(src++);
	}
	*ptr = '\0';
	return (dest);
}
