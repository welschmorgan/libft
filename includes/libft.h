/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:26:49 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/03 21:11:18 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

# define FT_INVALID_STR		"NULL"
# define _DEBUG_DLIST		0

# define FT_MIN(a, b)		(a < b ? a : b)
# define FT_MAX(a, b)		(a > b ? a : b)

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

/*
** Represents a policy to apply on each node
**	NF_NONE: no flags at all
**	NF_DESTROY_NODE: destroys node in remove functions
**	NF_DESTROY_DATA: destroys user data in remove functions
**	NF_DESTROY_ALL: destroys node & user data in remove functions
**	NF_STATE_HIDDEN: sets the node in hidden state
**	NF_STATE_STANDOUT: sets the node in standout mode
**	NF_STATE_SELECTED: sets the node selected
*/
typedef enum				e_dnode_flag
{
	NF_NONE = 0,
	NF_DESTROY_NODE = 1 << 1,
	NF_DESTROY_DATA = 1 << 2,
	NF_DESTROY_ALL = NF_DESTROY_NODE | NF_DESTROY_DATA
}							t_dnode_flag;

/*
** Represents a link inside the list
*/
typedef struct				s_dnode
{
	struct s_dlist			*parent;
	void					*data;
	struct s_dnode			*next;
	struct s_dnode			*prev;
	unsigned int			flag;
	size_t					size;
}							t_dnode;

typedef void				(*t_dnode_deleter)(t_dnode *);

void						ft_dlist_deleter(t_dnode *node);
/*
** Represents a linked list of t_dnodes
** Tail: the starting node of this list
** Head: the last node of this list
** Size: Optionnal, increments or decrements
** when you add or remove t_dnodes
*/
typedef struct				s_dlist
{
	size_t					size;
	t_dnode					*tail;
	t_dnode					*head;
}							t_dlist;

typedef struct				s_dlist_iter
{
	t_dlist					*list;
	t_dnode					*node;
	size_t					id;
}							t_dlist_iter;

typedef enum				e_bool
{
	FALSE = 0,
	TRUE = 1
}							t_bool;

typedef struct				s_strsplit_env
{
	char					c;
	char const				*str;
	char					*ptr;
	char					**ret;
	char					**p_ret;
	size_t					len;
	char					*orig;
}							t_strsplit_env;

typedef struct				s_llbtoa
{
	unsigned long long		num;
	unsigned				base;
	unsigned long long		div;
	unsigned long long		mod;
	char const				*range;
	char					sign;
	char					*buf;
	char					*pbuf;
	unsigned				max;
	unsigned				cur;
	unsigned				len;
}							t_llbtoa;

typedef int					(*t_content_comparator)(void *a, void *b);

void						*ft_memset(void *b, int c, size_t len);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dst, const void *src,
									size_t n);
void						*ft_realloc(void *ptr, size_t size);
void						*ft_calloc(size_t nelems, size_t size);
void						*ft_malloc(size_t bytes);

void						*ft_memccpy(void *dst, const void *src,
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

wchar_t						*ft_wstrnew(size_t n);
void						ft_wstrdel(wchar_t **as);
size_t						ft_wstrlen(const wchar_t *s);
wchar_t						*ft_wstrdup(const wchar_t *s1);
wchar_t						*ft_wstrndup(const wchar_t *s1, size_t n);
wchar_t						*ft_wstrcpy(wchar_t *dest, const wchar_t *src);
wchar_t						*ft_wstrncpy(wchar_t *dest, const wchar_t *src, size_t n);

wchar_t						*ft_wstrcat(wchar_t *s1, const wchar_t *s2);
wchar_t						*ft_wstrncat(wchar_t *s1, const wchar_t *s2, size_t n);
size_t						ft_wstrlcat(wchar_t *dst, const wchar_t *src, size_t size);
wchar_t						*ft_wstrchr(const wchar_t *s, int c);
wchar_t						*ft_wstrrchr(const wchar_t *s, int c);
wchar_t						*ft_wstrstr(const wchar_t *big, const wchar_t *little);
wchar_t						*ft_wstrnstr(const wchar_t *big, const wchar_t *little,
										size_t len);
int							ft_wstrcmp(const wchar_t *s1, const wchar_t *s2);
int							ft_wstrncmp(const wchar_t *s1, const wchar_t *s2,
										size_t n);
int							ft_wstrequ(wchar_t const *s1, wchar_t const *s2);
int							ft_wstrnequ(wchar_t const *s1, wchar_t const *s2,
										size_t n);
void						ft_wstrnclr(wchar_t *s, size_t n);
void						ft_wstrclr(wchar_t *s);

wchar_t						*ft_wstrnrot_one_r(wchar_t *str,
											   size_t n);
wchar_t						*ft_wstrnrot_one_l(wchar_t *str,
											   size_t n);
wchar_t						*ft_wstrnrot_r(wchar_t *str,
										   size_t n,
										   int count);
wchar_t						*ft_wstrnrot_l(wchar_t *str,
										   size_t n,
										   int count);

wchar_t						*ft_wstrnpad_l(wchar_t *str,
										   size_t n,
										   wchar_t c);
wchar_t						*ft_wstrnpad_r(wchar_t *str,
										   size_t n,
										   wchar_t c);
size_t						ft_wcstombs(char *dest,
										wchar_t const *src,
										size_t n);
const char					*ft_wctomb(wchar_t c);

char						*ft_strrealloc(char *str,
										   size_t new_size);


char						*ft_strdup(const char *s1);
char						*ft_strndup(const char *s1, size_t n);
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
int							ft_isdigit(int c);
int							ft_isupper(int c);
int							ft_islower(int c);


int							ft_toupper(int c);
int							ft_tolower(int c);

char						*ft_strtoupper(char *s);
char						*ft_strtolower(char *s);
char						*ft_strntoupper(char *s, size_t n);
char						*ft_strntolower(char *s, size_t n);

int							ft_strisupper(char const *str);
int							ft_strislower(char const *str);

void						*ft_memalloc(size_t size);
void						*ft_memdup(const void *src, size_t size);
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

char						*ft_strnpad_r(char *str,
										  size_t n,
										  char c);
char						*ft_strnpad_l(char *str,
										  size_t n,
										  char c);

char						*ft_strnrot_l(char *str,
										  size_t n,
										  int count);
char						*ft_strnrot_r(char *str,
										  size_t n,
										  int count);

char						*ft_strnrot_one_l(char *str,
											  size_t n);
char						*ft_strnrot_one_r(char *str,
											  size_t n);


int							ft_isanyof(char c,
									   char const *seps);
int							ft_wisanyof(wchar_t c,
										wchar_t const *seps);

int							ft_putwendl(wchar_t const *s);
int							ft_putwchar(wchar_t c);
int							ft_putwstr(wchar_t const *str);

int							ft_putwchar_fd(wchar_t c,
										  int fd);
int							ft_putwstr_fd(wchar_t const *str,
										 int fd);
int							ft_putwendl_fd(wchar_t const *str,
										  int fd);

int							ft_putendl(char const *s);
int							ft_putnbr(int nb);
int							ft_putchar(char c);
int							ft_putstr(char const *str);

int							ft_putchar_fd(char c, int fd);
int							ft_putstr_fd(char const *str, int fd);
int							ft_putendl_fd(char const *str, int fd);
int							ft_putnbr_fd(int nb, int fd);

char						*ft_itoa(int n);
char						*ft_utoa(unsigned n);
char						*ft_ltoa(long n);
char						*ft_lltoa(long long n);

char						*ft_ibtoa(int n, unsigned base);
char						*ft_ubtoa(unsigned n, unsigned base);
char						*ft_lbtoa(long n, unsigned base);
char						*ft_llbtoa(long long n, unsigned base);

char						*ft_ibtoa_s(int n,
										unsigned base,
										char *buf,
										size_t max);
char						*ft_ubtoa_s(unsigned n,
										unsigned base,
										char *buf,
										size_t max);
char						*ft_lbtoa_s(long n,
										unsigned base,
										char *buf,
										size_t max);
char						*ft_llbtoa_s(long long n,
										 unsigned base,
										 char *buf,
										 size_t max);

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

void						ft_dlist_destroy(t_dlist **list,
											t_dnode_deleter deleter);
t_dlist						*ft_dlist_dup(const t_dlist *source);
t_dlist						*ft_dlist_copy(t_dlist *dest,
										const t_dlist *source);
t_dlist						*ft_dlist_init(t_dlist *list);
t_dlist						*ft_dlist_new();
void						ft_dlist_remove(t_dlist *list,
											t_dnode **node,
											t_dnode_deleter deleter);

t_bool						ft_dlist_empty(t_dlist *list);
size_t						ft_dlist_size(t_dlist *list, int recompute);
t_dlist_iter				ft_dlist_begin(t_dlist *list);
t_dlist_iter				ft_dlist_end(t_dlist *list);

/*
** Adds a node to the list
*/
t_dnode						*ft_dlist_add_back(t_dlist *list,
											t_dnode *new_node);
t_dnode						*ft_dlist_add_front(t_dlist *list,
												t_dnode *new_node);
t_dnode						*ft_dlist_push_back(t_dlist *list,
												t_dnode *new_node);
t_dnode						*ft_dlist_push_front(t_dlist *list,
												t_dnode *new_node);
/*
** Creates a node from a string and adds it the the list
*/
t_dnode						*ft_dlist_add_back_str(t_dlist *lst,
												char const *str,
												unsigned int flags);
t_dnode						*ft_dlist_add_front_str(t_dlist *lst,
													char const *str,
													unsigned int flags);
t_dnode						*ft_dlist_add_back_strn(t_dlist *lst,
													char const *str,
													size_t const n,
													unsigned int flags);
t_dnode						*ft_dlist_add_front_strn(t_dlist *lst,
													char const *str,
													size_t const n,
													unsigned int flags);
t_dnode						*ft_dlist_push_back_str(t_dlist *lst,
													char const *str,
													unsigned int flags);
t_dnode						*ft_dlist_push_front_str(t_dlist *lst,
													char const *str,
													unsigned int flags);

void						ft_dlist_clear(t_dlist *list,
										t_dnode_deleter deleter);

int							ft_dlist_contains(t_dlist *list,
											t_dnode *node);

t_dnode						*ft_dlist_extract(t_dlist *list,
											t_dnode *node);
t_dnode						*ft_dnode_init(t_dnode *n,
										void *data,
										size_t size,
										int flags);
t_dnode						*ft_dnode_new(void *data,
										size_t size,
										unsigned int flags);

t_dnode						*ft_dnode_new_str(char const *str,
											unsigned int flags);
t_dnode						*ft_dnode_new_strn(char const *str,
											size_t const n,
											unsigned int flags);
char						*ft_dnode_flag_str(t_dnode *node);
char						*ft_dnode_flag_name(t_dnode_flag flag);

t_dnode						*ft_dlist_insert_before(t_dlist *list,
													t_dnode *new_node,
													t_dnode *next);
t_dnode						*ft_dlist_insert_after(t_dlist *list,
												t_dnode *new_node,
												t_dnode *prev);
t_dnode						*ft_dlist_insert_first(t_dlist *list,
												t_dnode *node);

/*
** iterator stuff
*/
t_dnode						*ft_dlist_iter_prev(t_dlist_iter *i);
t_dnode						*ft_dlist_iter_next(t_dlist_iter *i);

int							ft_dlist_iter_valid(t_dlist_iter *i);

t_dlist_iter				*ft_dlist_iter_begin(t_dlist_iter *i);
t_dlist_iter				*ft_dlist_iter_end(t_dlist_iter *i);

void						*ft_dlist_iter_data(t_dlist_iter *i);

t_dlist_iter				*ft_dlist_iter_reset(t_dlist_iter *i);
t_dlist_iter				*ft_dlist_iter_init(t_dlist_iter *i, t_dlist *l);

typedef int					(*t_dlist_iter_fn)(t_dlist_iter *);

int							ft_dlist_iterate(t_dlist *l, t_dlist_iter_fn fn);
int							ft_dlist_riterate(t_dlist *l, t_dlist_iter_fn fn);

#endif
