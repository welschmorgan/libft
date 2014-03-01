/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 03:13:42 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 04:12:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_memory.h"

void		*ft_memdup(const void *src, size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (!src)
		return (NULL);
	tmp = ft_memalloc(size);
	if (tmp)
		ft_memcpy(tmp, src, size);
	return (tmp);
}
