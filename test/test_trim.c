/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_trim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:12:52 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 12:19:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include <stdlib.h>

int	test_trim(char const *str, char const *match)
{
	char	*res;
	int		matched;

	res = ft_strtrim(str);
	matched = strcmp(res, match);
	printf("strtrim(\"%s\") (%u chars):\n\t\"%s\" (%u chars) -> %s\n", str, (t_uint)strlen(str), res, (t_uint)strlen(res), !matched ? "OK" : "KO");
	ft_strdel(&res);
	return (matched);
}

int	test_itoa(int n)
{
	char	*a;
	int		matched;
	a = ft_itoa(n);
	char	b[33];
	snprintf(b, 33, "%d", n);
	matched = strcmp(a, b);
	printf("itoa(%d): \"%s\" - libc: \"%s\" -> %s\n", n, a, b, !matched ? "OK" : "KO");
	return (matched);
}
int	main(void)
{
	test_trim("\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ", "Hello \t  Please\n Trim me !");
	test_itoa(INT_MIN);
	test_itoa(INT_MAX);
	test_itoa(-623);
	return (0);
}
