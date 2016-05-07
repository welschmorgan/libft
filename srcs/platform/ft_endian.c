/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:05:36 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/07 13:06:06 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_endian			ft_endian()
{
	static const int	test = 0x04030201;

	return (*((const char *)&test) == 0x01 ? ENDIAN_LITTLE : ENDIAN_BIG);
}

char const			*ft_endian_name()
{
	static char const	*g_names[] = {
		"little endian",
		"big endian"
	};
	return (g_names[ft_endian()]);
}
