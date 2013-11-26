/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:23:08 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/26 18:55:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p_cur;
	t_list	*p_dup;

	p_dup = ft_lstnew(lst->content, lst->content_size);
	p_cur = lst;
	while (p_cur)
	{
		ft_lstadd(&p_dup, f(p_cur));
		p_cur = p_cur->next;
	}
	return (p_dup);
}
