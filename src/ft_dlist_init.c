/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:16:04 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 11:26:37 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_dlist.h>

t_dlist	*ft_dlist_init(t_dlist *list)
{
	if (!list)
		return (list);
#ifdef _DEBUG
	ft_printf("Initialising list 0x%x...\n", list);
#endif
	list->tail = NULL;
	list->head = NULL;
	list->size = 0;
	return (list);
}
