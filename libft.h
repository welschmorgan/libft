/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:26:49 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 10:25:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define FT_INVALID_STR		"NULL"

typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef enum				e_bool
{
	FALSE = 0,
	TRUE = 1
}							t_bool;

typedef int					(*t_content_comparator)(void *a, void *b);

void						*ft_memset(void *b, int c, size_t len);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *restrict dst, const void *src,
									size_t n);
void						*ft_memccpy(void *restrict dst, const void *src,
										int c, size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);

char						*ft_strtrim(char const *s);
char						*ft_strtrim_sep(char const *s, char const *seps);
char						*ft_strsub(char const *s1, unsigned int start,
									size_t len);
char						**ft_strsplit(char const *s, char c);
char						*ft_strnew(size_t size);
char						*ft_strmapi(char const *str, char (*f)(unsigned int,
																char));
char						*ft_strmap(char const *str, char (*f)(char));
char						*ft_strjoin(char const *s1, char const *s2);
void						ft_striteri(char *s, void (*f)(unsigned int,
														char*));
int							ft_strnequ(char const *s1, char const *s2,
									size_t n);
int							ft_strequ(char const *s1, char const *s2);
void						ft_strdel(char **as);
void						ft_strclr(char *s);

size_t						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strncpy(char *dst, const char *src, size_t n);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strncat(char *s1, const char *s2, size_t n);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *big, const char *little);
char						*ft_strnstr(const char *big, const char *little,
										size_t len);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1, const char *s2,
									size_t n);

int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_isnumber(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);

int							ft_toupper(int c);
int							ft_tolower(int c);

void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
char						*ft_strltrim(char *str, char const *separators);
char						*ft_strrtrim(char *str, char const *separators);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, void (*f)(unsigned int,
														char *));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s, char
										(*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1, char const *s2,
									size_t n);
char						*ft_strsub(char const *s, unsigned int
									start, size_t len);
void						ft_putendl(char const *s);
void						ft_putnbr(int nb);

int							ft_isdigit(int c);
int							ft_isanyof(char c, char const *seps);

char						*ft_strndup(const char *s1, size_t n);

void						ft_putchar(char c);
void						ft_putstr(char const *str);

void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char const *str, int fd);
void						ft_putendl_fd(char const *str, int fd);
void						ft_putnbr_fd(int nb, int fd);
char						*ft_itoa(int n);

void						ft_lstadd(t_list **alst, t_list *new);
t_list						*ft_lstback(t_list *l);
void						ft_lstdel(t_list **alst, void (*del)(void *,
																size_t));
void						ft_lstdelone(t_list **alst, void (*del)(void *,
																	size_t s));
t_bool						ft_lsteq(t_list *a, t_list *b,
									t_content_comparator comp);
t_list						*ft_lstfront(t_list *l);
void						ft_lstiter(t_list *lst,
									void (*f)(t_list *elem));
t_list						*ft_lstlast(t_list *lst);
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list						*ft_lstnew(void const *content,
									size_t content_size);
t_list						*ft_lstpush_back(t_list **lst, t_list *new);
t_list						*ft_lstpush_front(t_list **lst, t_list *new);
size_t						ft_lstsize(t_list *lst);

#endif
