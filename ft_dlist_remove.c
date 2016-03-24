/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:16:37 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:54:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_memory.h>
#include <libft_dlist.h>

void	ft_dlist_remove(t_dlist *list, t_dnode **node, t_dnode_deleter deleter)
{
	if (!list || !node || !*node)
		return ;
	if (!deleter)
		deleter = ft_dlist_deleter;
	deleter(*node);
	if ((*node)->data && ((*node)->flag & NF_DESTROY_DATA))
		ft_memdel((void**)&(*node)->data);
	ft_dlist_extract(list, *node);
	if (((*node)->flag & NF_DESTROY_NODE))
		ft_memdel((void**)node);
}
