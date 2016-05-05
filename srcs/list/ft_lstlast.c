/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:55:30 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/01 21:55:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	t_list	*last;

	ptr = lst;
	last = NULL;
	while (ptr)
	{
		last = ptr;
		ptr = ptr->next;
	}
	return (last);
}
