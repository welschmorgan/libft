/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:24:05 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 10:04:48 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrtrim(char *str, char const *separators)
{
	char	*p_end;
	char	*p_start;
	size_t	len;

	len = ft_strlen(str);
	if (!len)
		return (str);
	p_end = str + (len - 1);
	p_start = str;
	while (p_start && p_end >= p_start && ft_isanyof(*p_end, separators))
	{
		*p_end = '\0';
		p_end--;
	}
	return (str);
}
