/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:15:42 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 15:15:51 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_memory.h>
#include <libft_dlist.h>

void	ft_dlist_destroy(t_dlist **list, t_dnode_deleter deleter)
{
	if (!list || !*list)
		return ;
	ft_dlist_clear(*list, deleter);
	ft_memdel((void**)list);
}
