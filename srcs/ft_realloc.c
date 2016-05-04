/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 23:57:42 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/02 00:10:10 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_malloc(size_t bytes)
{
	return (malloc(bytes));
}

void			*ft_calloc(size_t nelems, size_t size)
{
	return (ft_malloc(nelems * size));
}

void			*ft_realloc(void *ptr, size_t size)
{
	void		*ret;

	ret = NULL;
	if (!size)
	{
		if (ptr)
			free(ptr);
	}
	else
	{
		ret = ft_malloc(size);
		if (ret)
		{
			ft_memcpy(ret, (const void *)ptr, size);
			ft_memdel(&ptr);
		}
	}
	return (ret);
}
