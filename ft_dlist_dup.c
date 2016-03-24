/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:13:53 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 14:36:12 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist				*ft_dlist_dup(const t_dlist *source)
{
	t_dlist			*copy;

	copy = (t_dlist*)ft_memalloc(sizeof(t_dlist));
	ft_dlist_init(copy);
	return (ft_dlist_copy(copy, source));
}
