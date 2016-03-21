/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:23:08 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 13:34:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		push_back(t_list **lst, t_list *elem)
{
	t_list	*ptr;
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
		lst = ft_lstnew(elem, sizeof(elem));
	if (!elem->content_size)
		elem->content_size = sizeof(*elem);
	ptr = *lst;
	last = NULL;
	while (ptr)
	{
		last = ptr;
		ptr = ptr->next;
	}
	if (!last)
		*lst = elem;
	else
		last->next = elem;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p_cur;
	t_list	*p_dup;

	p_dup = NULL;
	p_cur = lst;
	while (p_cur)
	{
		push_back(&p_dup, f(p_cur));
		p_cur = p_cur->next;
	}
	return (p_dup);
}