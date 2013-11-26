/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:06:13 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 20:09:46 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	size_t	slen;
	char	*p_s1;
	char	*p_ret;
	char	*ret;

	slen = ft_strlen(s1);
	if (((start + len) > slen) || len == 0)
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	p_s1 = (char *)s1;
	p_ret = ret;
	while (start)
	{
		p_s1++;
		start--;
	}
	while (len--)
	{
		*(p_ret++) = *(p_s1++);
	}
	return (ret);
}
