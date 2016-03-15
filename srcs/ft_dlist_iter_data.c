/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:59:03 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:59:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

void				*ft_dlist_iter_data(t_dlist_iter *i)
{
	if (i && i->node)
		return (i->node->data);
	return (NULL);
}
