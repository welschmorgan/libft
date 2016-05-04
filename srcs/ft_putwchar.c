/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:36:22 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:10:18 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_putwchar(wchar_t c)
{
	return (ft_putwchar_fd(c, 1));
}

int							ft_putwchar_fd(wchar_t c,
										  int fd)
{
	const char				*mbs;

	mbs = ft_wctomb(c);
	return (ft_putstr_fd(mbs, fd));
}
