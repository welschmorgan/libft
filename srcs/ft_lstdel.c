/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:49:22 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 12:25:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p_it;
	t_list	*p_next;

	if (!alst || !*alst)
		return ;
	p_it = (*alst);
	p_next = (*alst)->next;
	ft_lstdelone(&p_it, del);
	if (p_next)
		ft_lstdel(&p_next, del);
	*alst = NULL;
}
