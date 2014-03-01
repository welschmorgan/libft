/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 03:08:05 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 11:43:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_list.h"

size_t		ft_lstsize(t_list *lst)
{
	size_t	ret;

	ret = 0;
	while (lst)
	{
		if (lst->content)
			ret++;
		lst = lst->next;
	}
	return (ret);
}
