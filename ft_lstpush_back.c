/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:24:35 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/20 09:48:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpush_back(t_list **lst, t_list *new)
{
	t_list		**old;
	t_list		**cur;

	if (!lst || !new)
		return (NULL);
	old = NULL;
	cur = lst;
	while (cur && *cur)
	{
		old = cur;
		cur = &(*cur)->next;
	}
	*cur = new;
	if (old)
		(*old)->next = *cur;
	return (new);
}
