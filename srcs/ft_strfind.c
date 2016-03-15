/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:16:16 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:07:38 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strfind(char *str,
							char c,
							int offset)
{
	int				i;

	i = offset;
	if (i < 0)
		return (-1);
	while (str[i] == c)
		i++;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			return (i);
		}
		i++;
	}
	return (-1);
}
