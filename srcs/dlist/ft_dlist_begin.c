/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_begin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:43:37 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:13:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist_iter	ft_dlist_begin(t_dlist *list)
{
	t_dlist_iter	it;

	ft_dlist_iter_init(&it, list);
	ft_dlist_iter_begin(&it);
	return (it);
}
