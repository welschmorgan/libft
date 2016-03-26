/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:23:08 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/26 14:38:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p_cur;
	t_list	*p_dup;
	t_list	*p_mapped;

	p_dup = NULL;
	p_cur = lst;
	while (p_cur)
	{
		p_mapped = f(p_cur);
		if (!p_mapped)
			return (NULL);
		ft_lstadd(&p_dup, p_mapped);
		if (!p_dup)
			return (NULL);
		p_cur = p_cur->next;
	}
	return (p_dup);
}
