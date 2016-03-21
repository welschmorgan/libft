/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:23:08 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 14:42:31 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p_cur;
	t_list	*p_dup;

	p_dup = NULL;
	p_cur = lst;
	while (p_cur)
	{
		printf("map: %p (%u)", p_cur, (unsigned)p_cur->content_size);
		ft_lstadd(&p_dup, f(p_cur));
		if (!p_dup)
			return (NULL);
		printf(" -> %p (%u)\n", p_dup, (unsigned)p_dup->content_size);
		p_cur = p_cur->next;
	}
	return (p_dup);
}
