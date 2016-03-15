/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:26:20 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:39:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list			*ft_lstpop_back(t_list **lst,
								void (*deleter)(void *, size_t))
{
	t_list		*i;
	t_list		*o;

	i = *lst;
	o = NULL;
	while (i && i->next)
		i = i->next;
	if (o)
	{
		if (i)
			o->next = i->next;
		else
			o->next = NULL;
	}
	if (i)
		ft_lstdelone(&i, deleter);
	return (o);
}
