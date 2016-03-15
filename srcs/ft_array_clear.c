/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:46:17 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:46:26 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_string.h>

t_array			*ft_array_clear(t_array *a)
{
	size_t		id;

	id = 0;
	while (id < a->capacity)
	{
		if (a->data[id])
			ft_strdel(&a->data[id]);
		a->data[id] = NULL;
		id++;
	}
	a->size = 0;
	return (a);
}
