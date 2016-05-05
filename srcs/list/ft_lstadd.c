/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:30 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 14:14:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	ft_lstpush_front(alst, new);
}
/*
**if (alst && *alst && new)
**{
**	new->next = *alst;
**	*alst = new;
**}
*/
