/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:44:02 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:44:09 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>

int				ft_array_iter(t_array *a, int (*pfn)(char *))
{
	size_t		id;
	int			c;

	id = 0;
	while (id < a->capacity)
	{
		c = pfn(a->data[id]);
		if (c != 0)
			return (c);
		id++;
	}
	return (0);
}
