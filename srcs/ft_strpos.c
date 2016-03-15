/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:09:31 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:09:34 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

int						ft_strpos(char const *str, char c)
{
	int					ret;

	ret = 0;
	while (str)
	{
		if (!*str)
			break ;
		if (*str == c)
			return (ret);
		str++;
		ret++;
	}
	return (-1);
}
