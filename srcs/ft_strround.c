/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strround.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:01:21 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 20:22:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char						*ft_strround(char *str, int precision)
{
	return (ft_strnround(str, ft_strlen(str), precision));
}

char						*ft_strnround(char *str, size_t n, int precision)
{
	char					*cur;
	char					*next;
	int						carry;

	precision = ((size_t)precision) > n ? (int)n : precision;
	cur = str + precision - 1;
	next = cur + 1;
	carry = 0;
	while (cur >= str
		   && *next > '5'
		   && *next <= '9')
	{
		carry = (((*cur + 1) - '0') % 10) == 0;
		*cur = (carry ? '0' : (*cur + 1));
		--cur;
		next = cur + 1;
	}
	*cur += carry;
	*(str + precision) = 0;
	return (str);
}
