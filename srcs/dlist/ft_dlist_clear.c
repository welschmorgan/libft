/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:15:08 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:14:25 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlist_clear(t_dlist *list, t_dnode_deleter deleter)
{
	t_dnode	*cur;
	t_dnode *next;

	cur = list->tail;
	while (cur)
	{
		next = cur->next;
		ft_dlist_remove(list, &cur, deleter);
		cur = next;
	}
	list->tail = NULL;
	list->head = NULL;
}
