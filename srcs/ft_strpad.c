/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:24:01 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 10:35:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strpad_l(char *str,
					 size_t const n,
					 char const c)
{
	size_t	len;
	char	*pstr;

	if (!str)
		return (str);
	len = ft_strlen(str);
	if (len >= n)
		return (str);
	while (len < n)
	{
		pstr = str + ft_strlen(str);
		while (pstr && pstr > str)
		{
			*pstr = *(pstr - 1);
			pstr--;
		}
		*pstr = c;
		len++;
	}
	str[n] = 0;
	return (str);
}

char	*ft_strpad_r(char *str,
					 size_t const n,
					 char const c)
{
	char	*pstr;
	char	*pend;

	if (!str)
		return (str);
	pend = str + n;
	pstr = str + ft_strlen(str);
	if (pstr >= pend)
		return (str);
	while (pstr < pend)
		*pstr++ = c;
	*pstr = 0;
	return (str);
}

char	*ft_strpad(char *str,
				   size_t const n,
				   char const c)
{
	size_t	delta;

	if (!str)
		return (str);
	delta = n - ft_strlen(str);
	ft_strpad_l(str, n - delta / 2, c);
	ft_strpad_r(str, n, c);
	return (str);
}
