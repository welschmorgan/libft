/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:15:08 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 12:24:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_dlist.h>

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
