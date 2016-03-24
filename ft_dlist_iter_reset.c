/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter_reset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:59:20 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:59:28 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

t_dlist_iter		*ft_dlist_iter_reset(t_dlist_iter *i)
{
	return (ft_dlist_iter_begin(i));
}
