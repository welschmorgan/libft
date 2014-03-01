/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:17:15 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 11:13:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_dlist.h>
#include <libft_printf.h>

t_dnode	*ft_dlist_push_back(t_dlist *list, t_dnode *new_node)
{
		return (ft_dlist_add_back(list, new_node));
}

t_dnode	*ft_dlist_add_back(t_dlist *list, t_dnode *new_node)
{
#ifdef _DEBUG
	ft_printf("Adding  node 0x%x to list 0x%x ...\n",
			  new_node, list);
#endif
	if (!list || !new_node)
		return (NULL);
	list->size++;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!list->tail)
		list->tail = list->head = new_node;
	else
	{
		new_node->prev = list->head;
		list->head->next = new_node;
		list->head = new_node;
	}
	return (new_node);
}
