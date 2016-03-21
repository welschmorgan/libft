/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:30 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 13:41:55 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	**cur;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = ft_lstnew(new, sizeof(t_list));
		return ;
	}
	cur = alst;
	while (*cur)
		cur = &cur->next;
	*cur = new;
}
/*
**if (alst && *alst && new)
**{
**	new->next = *alst;
**	*alst = new;
**}
*/
