/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:59:50 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 14:35:50 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_dlist_size(t_dlist *list, int recompute)
{
	t_dnode			*cur;

	if (!list)
		return (0);
	cur = list->tail;
	if (recompute)
	{
		list->size = 0;
		while (cur)
		{
			list->size++;
			cur = cur->next;
		}
	}
	return (list->size);
}
