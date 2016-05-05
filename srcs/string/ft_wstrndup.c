/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:27:47 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 19:27:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t						*ft_wstrndup(const wchar_t *s1, size_t n)
{
	wchar_t					*ret;

	ret = ft_wstrnew(n);
	return (ft_wstrncpy(ret, s1, n));
}
