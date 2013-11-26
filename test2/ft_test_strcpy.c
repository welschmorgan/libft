/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:20:23 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 10:28:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	ft_test_strcpy2(char *s1, const char *s2)
{
	int		res;
	char	*str1;

	res = 0;
	str1 = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	printf("Test : \"%s\"", s2);
	ft_strcpy(s1, s2);
	strcpy(str1, s2);
	if (strcmp(str1, s1))
		++res;
	printf("{ \"%s\" (your) - \"%s\" }", s1, str1);
	free(str1);
	ft_print_status(res);
	return (res);
}

int			ft_test_strcpy(void)
{
	int	res;
	char buffer[50];

	res = 0;
	ft_print_begin("ft_strcpy");
	res += ft_test_strcpy2(buffer, "Bonjour");
	res += ft_test_strcpy2(buffer, "");
	return (ft_print_end(res));
}
