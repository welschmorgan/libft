#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (s && *s)
	{
		ret ++;
		s ++;
	}
	return (ret);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	ret;

	ret = 0;
	while (s && *s && ret < maxlen)
	{
		ret ++;
		s ++;
	}
	return (ret);
}
