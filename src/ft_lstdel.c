/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:49:22 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 18:19:55 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p_it;

	if (!alst || !*alst)
		return;
	p_it = *alst;
	while (p_it)
	{
		if (p_it->content)
		{
			del(p_it->content, p_it->content_size);
			free(p_it->content);
		}
		p_it->content = NULL;
		p_it = p_it->next;
	}
	*alst = NULL;
}
