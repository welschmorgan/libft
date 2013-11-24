#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*ptr;

	ptr = str + (ft_strlen(str) - 1);
	while (str && *str
		   && ptr && *ptr
		   && (ptr != (str - 1)))
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr --;
	}
	return (NULL);
}
