/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:45:07 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 13:00:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	ret = (t_list*)ft_memalloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (!content || !content_size)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		ret->content_size = content_size;
		ret->content = ft_memalloc(content_size);
		ft_memcpy(ret->content, content, content_size);
	}
	ret->next = NULL;
	return (ret);
}
