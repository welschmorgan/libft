/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:17:15 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:45:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_dlist.h>
#include <libft_printf.h>
#include <libft_string.h>

t_dnode				*ft_dlist_push_back(t_dlist *list, t_dnode *new_node)
{
	return (ft_dlist_add_back(list, new_node));
}

t_dnode				*ft_dlist_push_back_str(t_dlist *lst,
											char const *str,
											unsigned int flags)
{
	return (ft_dlist_add_back_str(lst, str, flags));
}

t_dnode				*ft_dlist_add_back_str(t_dlist *lst,
										char const *str,
										unsigned int flags)
{
	return (ft_dlist_add_back(lst,
							ft_dnode_new_str(str,
											flags)));
}

t_dnode				*ft_dlist_add_back(t_dlist *list, t_dnode *new_node)
{
	return (ft_dlist_insert_after(list, new_node, NULL));
}
