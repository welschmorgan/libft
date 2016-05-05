/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:14:28 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 14:35:27 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist				*ft_dlist_copy(t_dlist *dest,
								const t_dlist *source)
{
	const t_dnode	*cur;

	if (!source || !dest)
		return (dest);
	cur = source->tail;
	while (cur != source->head)
	{
		ft_dlist_add_back(dest, ft_dnode_new(ft_memdup(cur->data, cur->size),
											cur->size,
											cur->flag));
		cur = cur->next;
	}
	return (dest);
}
