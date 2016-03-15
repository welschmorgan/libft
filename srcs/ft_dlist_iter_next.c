/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:57:03 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:57:06 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

t_dnode				*ft_dlist_iter_next(t_dlist_iter *i)
{
	if (!i)
		return (NULL);
	if (i->node)
	{
		i->node = i->node->next;
		i->id++;
	}
	return (i->node);
}
