/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:26:53 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/28 10:32:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_list.h"

t_list			*ft_lstpop_front(t_list **lst,
								void (*deleter)(void *, size_t))
{
	t_list		**ret;

	ret = &(*lst)->next;
	ft_lstdelone(lst, deleter);
	*lst = *ret;
	return (*ret);
}
