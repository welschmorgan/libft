/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:58 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 12:59:57 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t s))
{
	t_list	*ptr;

	if (!alst || !*alst)
		return ;
	ptr = *alst;
	if (ptr->content)
		del(ptr->content, ptr->content_size);
	ft_memdel((void**)alst);
}
