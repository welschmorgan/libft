/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:26:16 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 11:27:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft_dlist.h>
#include <libft_memory.h>

t_dlist	*ft_dlist_new()
{
	t_dlist	*ret;

	ret = (t_dlist*)ft_memalloc(sizeof(t_dlist));
	return (ft_dlist_init(ret));
}