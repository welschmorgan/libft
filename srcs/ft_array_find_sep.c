/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_find_sep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:41:54 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:42:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"
#include "libft_string.h"

size_t					ft_array_find_sep(t_array const *array,
										char const *name,
										char sep)
{
	size_t				id;

	id = 0;
	while (id < array->capacity)
	{
		if (array->data[id])
		{
			if (ft_strnequ(array->data[id], name, ft_strlen(name))
				&& array->data[id][ft_strlen(name)] == sep)
				return (id);
		}
		id++;
	}
	return (NPOS);
}
