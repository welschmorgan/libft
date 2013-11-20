/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:54:48 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/20 20:23:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT__H
# define LIBFT__H
# include <string.h>


typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;

typedef	t_uint*			t_uint_ptr;
typedef t_uchar			t_uchar_ptr;
typedef t_ushort*		t_ushort_ptr;

/*
 * Checks if two memory regions overlap
 * Returns 1 if a is inside b
 */
int		ft_memoverlap(void *a, const void *b, size_t count);

/*
 * Memory functions
 */
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *b, size_t len);


/* Str manipulation funcs */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(char *str, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/* Others */
int		ft_atoi(const char *str);

/* Char manip funcs */
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);

#endif /* !LIBFT__H */
