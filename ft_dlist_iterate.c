/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iterate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:11 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:08:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_dlist_riterate(t_dlist *l, t_dlist_iter_fn fn)
{
	t_dlist_iter			it;
	size_t					id;
	int						c;

	it = ft_dlist_end(l);
	id = l->size;
	while (ft_dlist_iter_valid(&it))
	{
		c = fn(&it);
		if (c)
			break ;
		ft_dlist_iter_prev(&it);
		id--;
	}
	return (c);
}

int					ft_dlist_iterate(t_dlist *l, t_dlist_iter_fn fn)
{
	t_dlist_iter			it;
	size_t					id;
	int						c;

	it = ft_dlist_begin(l);
	id = 0;
	while (ft_dlist_iter_valid(&it))
	{
		c = fn(&it);
		if (c)
			break ;
		ft_dlist_iter_next(&it);
		id++;
	}
	return (c);
}
