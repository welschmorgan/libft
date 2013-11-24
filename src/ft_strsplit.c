#include "libft.h"

size_t	ft_count_words(char const *s, char sep)
{
	size_t		ret;

	ret = 0;
	while (s && *s)
	{
		if (*s == sep)
			ret ++;
		while (*s == sep)
		{
			s++;
		}
		s ++;
	}
	return (ret);
}
size_t	ft_strlen_ptr(char const *start, char const *end)
{
	return ((unsigned char*)end - (unsigned char *)start);
}
char	**ft_strsplit(char const *s, char c)
{
	char				**ret;
	char				**pret;
	char const			*pstart;
	char const			*pend;
	char const			*porig;

	ret = (char**)ft_memalloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	pstart = NULL;
	pend = NULL;
	pret = ret;
	porig = s;
	while (s && *s)
	{
		if (*s == c)
		{
			pstart = NULL;
			pend = NULL;
			ret ++;
			pret = ret;
		}
		while (*s == c)
			s++;
		if (*s != c)
			pstart = s;
		while (*s != c)
		{
			pend = s;
			s ++;
		}
		if (pstart && pend)
		{
			*pret = ft_strsub(porig, ft_strlen_ptr(porig, pstart), ft_strlen_ptr(pstart, pend));
		}
		s ++;
	}
	*pret = NULL;
	return (ret);
}
