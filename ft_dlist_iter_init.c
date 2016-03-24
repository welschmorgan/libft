/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:55:17 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:55:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

t_dlist_iter		*ft_dlist_iter_init(t_dlist_iter *i, t_dlist *l)
{
	if (!i)
		return (i);
	i->list = l;
	i->node = NULL;
	i->id = 0;
	ft_dlist_iter_reset(i);
	return (i);
}
