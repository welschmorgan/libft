/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 05:14:48 by DarkBoss          #+#    #+#             */
/*   Updated: 2016/03/09 14:08:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrealloc(void *buf, size_t size)
{
	void	*tmp;

	if (!buf)
		return (ft_memalloc(size));
	if (!size && buf)
	{
		ft_memdel(&buf);
		return (buf);
	}
	tmp = ft_memalloc(size);
	ft_memcpy(tmp, buf, size);
	ft_memdel(&buf);
	return (tmp);
}
