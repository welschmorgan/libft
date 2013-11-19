/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:54:48 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/19 19:00:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT__H
# define LIBFT__H
# include <string.h>

/* Memory functions */
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *b, size_t len);


/* Str manipulation funcs */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dest, const char *src);

/* Char manip funcs */
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);

#endif /* !LIBFT__H */
