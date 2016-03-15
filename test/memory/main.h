#ifndef MAIN_HH
# define MAIN_HH

# include "common.h"

# define CHUNK_SIZE 10
# define CHUNK_STRIDE sizeof(char)


int				test_alloc();
int				test_dealloc();

int				test_copy();
int				test_copy_overflow();
int				test_set();

extern void		*g_buf;

void			print_chunk(void *chunk);

#endif
