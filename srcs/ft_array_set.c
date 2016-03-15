/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:45:20 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 15:00:47 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_string.h>

char			*ft_array_set(t_array *dst, size_t id,
							char const *value)
{
	if (id >= dst->capacity)
		return (NULL);
	if (dst->data[id])
	{
		ft_strdel(&dst->data[id]);
	}
	if (value)
	{
		dst->data[id] = ft_strdup(value);
		if ((id + 1) >= dst->size)
			dst->size = id + 1;
	}
	else
	{
		dst->data[id] = NULL;
		dst->size = id;
	}
	return (dst->data[id]);
}
