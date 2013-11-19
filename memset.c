#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pstart;
	unsigned char	*pend;

	pstart = (unsigned char *)b;
	pend = pstart + len;
	while (pstart != pend)
	{
		*pstart = c;
		pstart ++;
	}
	return (b);
}
