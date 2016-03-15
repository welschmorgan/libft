/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:58:16 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:58:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

t_dlist_iter		*ft_dlist_iter_end(t_dlist_iter *i)
{
	if (i && i->list)
	{
		i->node = i->list->head;
		i->id = 0;
		if (i->list->size)
			i->id = i->list->size - 1;
	}
	return (i);
}
