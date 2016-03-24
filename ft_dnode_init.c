/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dnode_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:00:32 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:18:40 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode	*ft_dnode_init(t_dnode *n, void *data, size_t size, int flags)
{
	if (!n)
		return (n);
	n->parent = NULL;
	n->prev = NULL;
	n->next = NULL;
	n->size = size;
	n->data = data;
	n->flag = flags;
	return (n);
}
