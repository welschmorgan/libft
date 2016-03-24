/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dnode_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:00:50 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/24 16:18:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode		*ft_dnode_new(void *data, size_t size, unsigned int flags)
{
	t_dnode	*ret;

	ret = (t_dnode*)ft_memalloc(sizeof(t_dnode));
	if (!ret)
		return (ret);
	ft_dnode_init(ret, data, size, flags);
	return (ret);
}
