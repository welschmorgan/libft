#ifndef LIBFT__H
# define LIBFT__H
# include <string.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *b, size_t len);

/* Str manipulation funcs */
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);

#endif /* !LIBFT__H */
