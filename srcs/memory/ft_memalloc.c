/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:45:15 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 02:54:37 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (!size || !(ptr = malloc(size)))
		return (ptr);
	ft_memset(ptr, 0, size);
	return (ptr);
}
