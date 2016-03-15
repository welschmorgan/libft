/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:52:52 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 14:50:55 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_memory.h>
#include <libft_string.h>

size_t					ft_array_append(t_array *a,
										char const *val)
{
	char			**data;
	size_t			id;

	if (a->size + 1 >= a->capacity)
	{
		data = (char**)ft_memalloc(sizeof(char*) * a->capacity + 1);
		id = 0;
		while (id < a->capacity)
		{
			data[id] = ft_strdup(a->data[id]);
			id++;
		}
		ft_array_copy_raw(a, data, a->capacity + 1, TRUE);
	}
	else
	{
		id = a->size;
	}
	ft_array_set(a, id, val);
	return (id);
}
