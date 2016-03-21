/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:23:44 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 11:18:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strltrim(char *str, char const *separators)
{
	char	*ptr;

	if (!str || !*str)
		return (str);
	while (str && ft_isanyof(*str, separators))
	{
		ptr = str;
		while (ptr && *ptr)
		{
			*ptr = *(ptr + 1);
			ptr++;
		}
	}
	return (str);
}
