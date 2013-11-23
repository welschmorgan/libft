/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:45:07 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 19:53:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (content)
	{
		ret->content = ft_memalloc(content_size);
		ret->content_size = content_size;
		
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	ret->next = (NULL);
	return (ret);
}
