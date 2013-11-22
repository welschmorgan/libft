/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:27:03 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 22:27:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isanyof(char c, char const *seps)
{
	while (seps && *seps)
	{
		if (c == *(seps++))
			return (TRUE);
	}
	return (FALSE);
}

char	*ft_strltrim(char *str, char const *separators)
{
	while (str && *str && ft_isanyof(*str, separators))
		str ++;
	return (str);
}

char	*ft_strrtrim(char *str, char const *separators)
{
	char	*p_end;
	char	*p_start;
	size_t	len;

	len = ft_strlen(str);
	if (!len)
		return (NULL);
	p_end = str + (len - 1);
	p_start = str;
	while (p_start > p_end && ft_isanyof(*p_end, separators))
	{
		*p_end = '\0';
		p_end --;
	}
	return (str);
}

char	*ft_strtrim(char const *s)
{
	char				*ret;
	char const			seps[] = " \n\t";
	size_t				len;

	len = ft_strlen(s);
	if (!len)
		return (NULL);
	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	return (ft_strltrim(ft_strrtrim(ret, seps), seps));
}
