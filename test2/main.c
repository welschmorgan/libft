/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:33:54 by amerle            #+#    #+#             */
/*   Updated: 2013/11/25 21:45:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int			main(void)
{
	int		res;
	int 	percent;

	signal(SIGSEGV, ft_segfault);
	signal(SIGBUS, ft_buserror);

	g_tests = 0;
	g_tests_ok = 0;

	res = 0;
	res += ft_test_memset();
	res += ft_test_bzero();
	res += ft_test_memcpy();
	res += ft_test_memccpy();
	res += ft_test_memmove();
	res += ft_test_memchr();
	res += ft_test_memcmp();
	res += ft_test_strlen();
	res += ft_test_strdup();
	res += ft_test_strcpy();
	res += ft_test_strncpy();
	res += ft_test_strcat();
	res += ft_test_strncat();
	res += ft_test_strlcat();
	res += ft_test_strchr();
	res += ft_test_strrchr();
	res += ft_test_strstr();
	res += ft_test_strnstr();
	res += ft_test_strcmp();
	res += ft_test_strncmp();
	res += ft_test_atoi();
	res += ft_test_isalpha();
	res += ft_test_isdigit();
	res += ft_test_isalnum();
	res += ft_test_isascii();
	res += ft_test_isprint();
	res += ft_test_toupper();
	res += ft_test_tolower();
	res += ft_test_memallocdel();
	res += ft_test_strnew();
	res += ft_test_strclr();
	res += ft_test_striter();
	res += ft_test_strmap();
	res += ft_test_strequ();
	res += ft_test_strsub();
	res += ft_test_strjoin();
	res += ft_test_strtrim();
	res += ft_test_strsplit();
	res += ft_test_itoa();
	res += ft_test_putchar();
	res += ft_test_putstr();
	res += ft_test_putendl();
	res += ft_test_putnbr();
	res += ft_test_putchar_fd();
	res += ft_test_putstr_fd();
	res += ft_test_putendl_fd();
	res += ft_test_putnbr_fd();
	res += ft_test_lstnew();
	res += ft_test_lstdelone();
	res += ft_test_lstdel();
	res += ft_test_lstadd();
	res += ft_test_lstiter();
	res += ft_test_lstmap();

	percent = g_tests_ok * 100 / g_tests;
	printf("\nPourcentage de reussite : \033[%dm%d\033[0m %%\n", (percent == 100) ? 32 : ((percent >= 70) ? 33 : 31), percent);
	printf("Nombre d'erreurs : %d\n", res);
	if (percent == 100)
		res = system("osascript -e 'say \"You have past all tests\" using \"Victoria\"'");
	else if (percent >= 70)
		res = system("osascript -e 'say \"You have past a major part of test\" using \"Victoria\"'");
	else
		res = system("osascript -e 'say \"Try again\" using \"Victoria\"'");
	return (0);
}
