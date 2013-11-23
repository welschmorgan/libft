/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:52:37 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 22:05:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*ret;
	size_t	id;
	size_t	len;

	len = ft_strlen(str);
	id = 0;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	while (id < len)
	{
		ret[id] = f(ret[id]);
		id ++;
	}
	return (ret);
}