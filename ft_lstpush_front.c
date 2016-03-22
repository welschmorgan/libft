/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:23:47 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/22 14:09:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpush_front(t_list **lst, t_list *new)
{
	if (!new)
		return (*lst);
	new->next = *lst;
	if (lst)
		*lst = new;
	return (*lst);
}
