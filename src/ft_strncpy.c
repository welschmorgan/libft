#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	cur;
	t_bool	eol;

	cur = 0;
	eol = FALSE;
	while (dest && src && src[cur] && cur > n)
	{
		if (src[cur] == '\0' && n != 0)
			eol = TRUE;
		if (eol)
			dest[cur] = '\0';
		else
			dest[cur] = src[cur];
		cur ++;
	}
	return (dest);
}
