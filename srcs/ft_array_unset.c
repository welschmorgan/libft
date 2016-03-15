/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:44:36 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:54:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_string.h>

t_array			*ft_array_unset(t_array *dst, size_t id)
{
	if (id >= dst->capacity || !dst->data[id])
		return (dst);
	ft_strdel(&dst->data[id]);
	if (dst->size > 0)
		dst->size--;
	while (id < dst->capacity)
	{
		dst->data[id] = dst->data[id + 1];
		id++;
	}
	dst->data[id] = NULL;
	return (dst);
}
