/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrpad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 21:38:05 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:38:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrnpad_l(wchar_t *str,
						   size_t n,
						   wchar_t c)
{
	int		len;
	int		diff;

	len = ft_wstrlen(str);
	len = len > (int)n ? (int)n : len;
	diff = ((int)n) - len;
	if (diff > 0)
	{
		ft_wstrnrot_r(str, n, diff);
		ft_memset((void*)str, c, sizeof(wchar_t) * diff);
	}
	return (str);
}

wchar_t		*ft_wstrnpad_r(wchar_t *str,
						   size_t n,
						   wchar_t c)
{
	int		len;
	int		diff;

	len = ft_wstrlen(str);
	len = len > (int)n ? (int)n : len;
	diff = ((int)n) - len;
	if (diff > 0)
		ft_memset((void*)(str + len), c, sizeof(wchar_t) * diff);
	return (str);
}
