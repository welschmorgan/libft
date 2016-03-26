/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:56:34 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:08:34 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode				*ft_dlist_iter_prev(t_dlist_iter *i)
{
	if (!i)
		return (NULL);
	if (i->node)
	{
		i->node = i->node->prev;
		i->id--;
	}
	return (i->node);
}
