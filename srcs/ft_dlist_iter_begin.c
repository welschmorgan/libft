/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_begin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:57:51 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:01:04 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

t_dlist_iter		*ft_dlist_iter_begin(t_dlist_iter *i)
{
	if (i && i->list)
	{
		i->node = i->list->tail;
		i->id = 0;
	}
	return (i);
}
