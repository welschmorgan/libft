/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:45:50 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:46:05 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_string.h>

size_t			ft_array_find(t_array const *a, char const *key)
{
	size_t		id;

	id = 0;
	while (id < a->capacity)
	{
		if (ft_strequ(a->data[id], key))
			return (id);
		id++;
	}
	return (NPOS);
}
