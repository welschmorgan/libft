/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:18:04 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:14:13 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dnode				*ft_dlist_push_front(t_dlist *list, t_dnode *new_node)
{
	return (ft_dlist_add_front(list, new_node));
}

t_dnode				*ft_dlist_add_front(t_dlist *list, t_dnode *new_node)
{
	return (ft_dlist_insert_before(list, new_node, NULL));
}

t_dnode				*ft_dlist_push_front_str(t_dlist *lst,
											char const *str,
											unsigned int flags)
{
	return (ft_dlist_add_front_str(lst, str, flags));
}

t_dnode				*ft_dlist_add_front_str(t_dlist *lst,
										char const *str,
										unsigned int flags)
{
	return (ft_dlist_add_front(lst,
							ft_dnode_new_str(str,
												flags)));
}
