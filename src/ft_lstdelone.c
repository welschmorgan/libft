/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:58 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/22 18:45:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t s))
{
	t_list		*p_cur;

	if (!alst || !*alst)
		return ;
	p_cur = (*alst);
	while (p_cur)
	{
		if (p_cur->content)
		{
			del(p_cur->content, p_cur->content_size);
			free(p_cur->content);
		}
		p_cur->content = NULL;
		p_cur = p_cur->next;
	}
}
