/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:42:26 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:57:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_putwstr(wchar_t const *str)
{
	return (ft_putwstr_fd(str, 1));
}

int							ft_putwstr_fd(wchar_t const *str,
										 int fd)
{
	int				len;

	len = 0;
	while (str && *str)
		len += ft_putwchar_fd(*str++, fd);
	return (len);
}
