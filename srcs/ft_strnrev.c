/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:09:14 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:09:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char			*ft_strnrev(char *str, size_t n)
{
	int			ids;
	int			ide;
	char		tmp;

	if (!str || !*str)
		return (str);
	ids = 0;
	ide = ft_strlen(str) - 1;
	while (ids < ide && str[ids] && n--)
	{
		tmp = str[ide];
		str[ide] = str[ids];
		str[ids] = tmp;
		ids++;
		ide--;
	}
	return (str);
}
