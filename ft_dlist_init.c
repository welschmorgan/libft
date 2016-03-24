/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:16:04 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:50:27 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_dlist.h>

t_dlist	*ft_dlist_init(t_dlist *list)
{
	if (!list)
		return (list);
	list->tail = NULL;
	list->head = NULL;
	list->size = 0;
	return (list);
}
