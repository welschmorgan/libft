/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:26:49 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/19 12:59:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memccpy(void *restrict dst, const void *restrict src, int c,
					size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strcat(char *restrict s1, const char *restrict s2);
char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isnumber(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

int			ft_toupper(int c);
int			ft_tolower(int c);

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int,
										char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char
						(*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2,
					size_t n);
char		*ft_strsub(char const *s, unsigned int
					start, size_t len);
void		ft_putendl(char const *s);
void		ft_putnbr_fd(int n, int fd);

int			ft_isdigit(int c);
int			ft_isanyof(char c, char const *seps);

char		*ft_strndup(const char *s1, size_t n);

#endif
