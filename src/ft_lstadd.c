/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:30 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 19:55:25 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*p_cur;
	t_list		*p_last;

	if (!alst || !*alst)
		return ;
	p_cur = *alst;
	while (p_cur)
	{
		p_last = p_cur;
		p_cur = p_cur->next;
	}
	p_cur = new;
	if (p_last)
		p_last->next = p_cur;
}
