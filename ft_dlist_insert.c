/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:51:31 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:54:12 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_dlist.h>
#include <libft_memory.h>
#include <libft_printf.h>
#include <libft_string.h>

t_dnode				*ft_dlist_insert_first(t_dlist *list, t_dnode *node)
{
	if (list && node)
	{
		list->tail = node;
		list->head = NULL;
		list->tail->next = list->head;
		list->tail->prev = NULL;
		list->size = 1;
	}
	return (node);
}

t_dnode				*ft_dlist_insert_after(t_dlist *list, t_dnode *new_node,
										t_dnode *prev)
{
	if (!new_node || !list)
		return (new_node);
	if (!prev)
		prev = list->head;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->parent = list;
	new_node->prev = prev;
	new_node->next = prev ? prev->next : NULL;
	if (prev)
		prev->next = new_node;
	if (new_node->next)
		new_node->next->prev = new_node->prev;
	if (!list->tail)
		list->tail = new_node;
	if (!new_node->next)
		list->head = new_node;
	list->size++;
	return (new_node);
}

t_dnode				*ft_dlist_insert_before(t_dlist *list,
											t_dnode *new_node,
											t_dnode *next)
{
	if (!new_node || !list)
		return (new_node);
	if (!next)
		next = list->tail;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->parent = list;
	new_node->prev = next ? next->prev : NULL;
	new_node->next = next;
	if (next)
		next->prev = new_node;
	if (new_node->prev)
		new_node->prev->next = new_node;
	if (!list->tail)
		list->tail = new_node;
	if (!new_node->next)
		list->head = new_node;
	list->size++;
	return (new_node);
}
