/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:41:47 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:41:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

t_dlist_iter	ft_dlist_end(t_dlist *list)
{
	t_dlist_iter	it;

	ft_dlist_iter_init(&it, list);
	ft_dlist_iter_end(&it);
	return (it);
}
