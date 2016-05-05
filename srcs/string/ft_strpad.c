/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 12:39:59 by mwelsch           #+#    #+#             */
/*   Updated: 2016/04/30 12:58:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnpad_l(char *str,
						  size_t n,
						  char c)
{
	int		len;
	int		diff;

	len = ft_strlen(str);
	len = len > (int)n ? (int)n : len;
	diff = ((int)n) - len;
	if (diff > 0)
	{
		ft_strnrot_r(str, n, diff);
		ft_memset((void*)str, c, sizeof(char) * diff);
	}
	return (str);
}

char		*ft_strnpad_r(char *str,
						  size_t n,
						  char c)
{
	int		len;
	int		diff;

	len = ft_strlen(str);
	len = len > (int)n ? (int)n : len;
	diff = ((int)n) - len;
	if (diff > 0)
		ft_memset((void*)(str + len), c, sizeof(char) * diff);
	return (str);
}
