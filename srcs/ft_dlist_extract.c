/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:50:46 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:09:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_dlist_contains(t_dlist *list,
									t_dnode *node)
{
	t_dnode			*cur;

	if (!list)
		return (0);
	cur = list->tail;
	while (cur && cur != node)
		cur = cur->next;
	return (cur == node);
}

t_dnode				*ft_dlist_extract(t_dlist *list,
									t_dnode *node)
{
	if (!list || !node)
		return (node);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (list->tail == node || !list->tail)
		list->tail = node->next;
	if (!node->next)
		list->head = (node->prev ? node->prev : list->tail);
	if (list->size)
		list->size--;
	node->parent = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
