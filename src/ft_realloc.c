/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:11:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 04:25:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_realloc(void *ptr, size_t size)
{
	void			*dup;

	dup = ft_memalloc(size);
	if (ptr)
	{
		if (dup)
			ft_memcpy(dup, ptr, size);
		ft_memdel(&ptr);
	}
	return (dup);
}
