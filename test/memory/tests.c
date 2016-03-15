#include "main.h"
#include "libft.h"

void		*g_buf = NULL;

void		print_chunk(void *chunk)
{
	void		*ptr;
	void		*end;
	size_t		col;
	char		addr[20];
	static char	line[255] = {0};
	size_t		sz;

	ptr = chunk;
	end = chunk + CHUNK_SIZE * CHUNK_STRIDE + 1;
	col = 0;
	while (ptr && ptr < end)
	{
		sz = ft_strlen(line);
		if (!(col % 4))
		{
			ft_putendl(line);
			ft_memset(line, 0, CHUNK_SIZE);
			ft_snprintf(addr, 20, "%x(+%d)", ptr, (ptr - chunk) / CHUNK_STRIDE);
			ft_snprintf(line, 255, "%s | ", ft_strpad_l(addr, 20, ' '));
		}
		ft_snprintf(line + sz - 1, 255, "%d", (*(char*)ptr));
		col++;
		ptr += CHUNK_STRIDE;
	}
	ft_putendl(line);
}
int		test_alloc()
{
	g_buf = ft_memalloc(CHUNK_SIZE * CHUNK_STRIDE);
	print_chunk(g_buf);
	return (0);
}

int		test_dealloc()
{
	print_chunk(g_buf);
	ft_memdel(&g_buf);
	return (0);
}

int		test_copy_overflow()
{
	ft_memcpy(g_buf, "7 bytes, plus a lot of junk", CHUNK_SIZE);
	print_chunk(g_buf);
	return (0);
}
int		test_copy()
{
	ft_memcpy(g_buf, "7 bytes", CHUNK_SIZE);
	print_chunk(g_buf);
	return (0);
}

int		test_set()
{
	ft_memset(g_buf, 0, CHUNK_SIZE);
	print_chunk(g_buf);
	return (0);
}
