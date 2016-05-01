/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:16:56 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:49:13 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrnew(size_t n)
{
	wchar_t		*ptr;

	ptr = (wchar_t*)ft_memalloc(sizeof(wchar_t) * (n + 1));
	if (!ptr)
		return (NULL);
	ft_memset((void*)ptr, 0, sizeof(wchar_t) * n);
	return (ptr);
}
