/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:31:35 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 11:25:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include <libft_config.h>

/*
 * Str manipulation funcs
 */
int						ft_strfind_any(char *str, char const *seps, int offset);
int						ft_strfind(char *str, char c, int offset);
char					**ft_strtok(char *str, char const *seps);
t_bool					ft_strmatch(const char *str, const char *pattern);
int						ft_readline(int fd, char *buf, size_t buf_max);
t_bool					ft_strempty(const char *str);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *src);
char					*ft_strndup(const char *src, size_t max);
int						ft_strcmp(const char *dest, const char *src);
int						ft_strncmp(const char *dest, const char *src, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *s));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t sz);
char					*ft_strsub(char const *s,
								   unsigned int start,
								   size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
t_bool					ft_isanyof(char c, char const *seps);
char					*ft_strltrim(char *str, char const *separators);
char					*ft_strrtrim(char *str, char const *separators);
char					*ft_strtrim(char *s, char const *seps);
char					**ft_strsplit(char const *s, char c);
t_bool					ft_isempty(char const *str);
char					*ft_strrev(char *str);

int						ft_putchar(char c);
int						ft_putstr(char const *s);
int						ft_putendl(char const *s);
int						ft_putnbr(int num);

int						ft_putchar_fd(char c, int fd);
int						ft_putstr_fd(char const * s, int fd);
int						ft_putendl_fd(char const *s, int fd);
int						ft_putnbr_fd(int num, int fd);

char					*ft_strtolower(char *s);
char					*ft_strtoupper(char *s);

int						ft_isupper(char c);
int						ft_islower(char c);
int						ft_isspace(char c);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_isprint(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_isalnum(int c);

void					ft_swapc(char *a, char *b);
void					ft_swapi(int *a, int *b);

void					ft_tokdel(char ***tokens);
int						ft_getline(int fd, char **user_buf);

#endif /* !LIBFT_STRING_H */
