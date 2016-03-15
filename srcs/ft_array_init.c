/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:46:41 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:52:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_memory.h>

t_array			*ft_array_init(t_array *a, size_t len)
{
	size_t		id;

	a->size = 0;
	a->capacity = len;
	a->data = (char**)ft_memalloc(sizeof(char *) * (len + 1));
	id = 0;
	while (id < len)
	{
		a->data[id] = NULL;
		id++;
	}
	a->data[id] = NULL;
	return (a);
}
