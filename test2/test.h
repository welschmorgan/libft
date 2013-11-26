/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 06:55:12 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 03:29:30 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <libft.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <signal.h>
# include <fcntl.h>
# include <unistd.h>

struct	s_struct1
{
	char	*m_str;
	char	m_char;
	int		m_int;
	void	*m_pointer;
};

struct	s_memtest
{
	char	c;
	char	c3;
	char	c2;
	int		num2;
	char 	c4;
};

typedef struct s_struct1	t_struct1;
typedef struct s_memtest	t_memtest;

void	ft_segfault(int);
void	ft_buserror(int);

void	ft_print_status(int res);
void	ft_print_warning(char const *s);
void	ft_print_error(char const *s);
void	ft_print_begin(const char *name);
int		ft_print_end(int res);
int		ft_test_strcmp(void);
int		ft_test_memset(void);
int		ft_test_bzero(void);
int		ft_test_memcpy(void);
int		ft_test_memccpy(void);
int		ft_test_memmove(void);
int		ft_test_memchr(void);
int		ft_test_memcmp(void);
int		ft_test_strlen(void);
int		ft_test_strdup(void);
int		ft_test_strcpy(void);
int		ft_test_strncpy(void);
int		ft_test_strchr(void);
int		ft_test_strrchr(void);
int		ft_test_strcat(void);
int		ft_test_strncat(void);
int		ft_test_strlcat(void);
int 	ft_test_strstr(void);
int 	ft_test_strncmp(void);
int 	ft_test_strnstr(void);
int 	ft_test_atoi(void);
int 	ft_test_isalpha(void);
int 	ft_test_isdigit(void);
int 	ft_test_isalnum(void);
int 	ft_test_isascii(void);
int 	ft_test_isprint(void);
int 	ft_test_toupper(void);
int 	ft_test_tolower(void);
int 	ft_test_memallocdel(void);
int 	ft_test_strnew(void);
int 	ft_test_strclr(void);
int 	ft_test_striter(void);
int 	ft_test_strmap(void);
int 	ft_test_strequ(void);
int 	ft_test_strsub(void);
int 	ft_test_strjoin(void);
int 	ft_test_strtrim(void);
int 	ft_test_strsplit(void);
int 	ft_test_itoa(void);
int 	ft_test_putchar(void);
int 	ft_test_putstr(void);
int 	ft_test_putendl(void);
int 	ft_test_putnbr(void);
int 	ft_test_putchar_fd(void);
int 	ft_test_putstr_fd(void);
int 	ft_test_putendl_fd(void);
int 	ft_test_putnbr_fd(void);
int 	ft_test_lstnew(void);
int 	ft_test_lstdelone(void);
int 	ft_test_lstdel(void);
int 	ft_test_lstadd(void);
int 	ft_test_lstiter(void);
int 	ft_test_lstmap(void);

int	g_tests_ok;
int g_tests;

#endif
