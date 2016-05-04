/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:40:33 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:01:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void						ft_putwendl(wchar_t const *s)
{
	ft_putwendl_fd(s, 1);
}

void						ft_putwendl_fd(wchar_t const *str,
										  int fd)
{
	size_t					len;

	len = ft_wstrlen(str);
	ft_putwstr_fd(str, fd);
	if (str && str[len] != '\n')
		ft_putwstr_fd(L"\n", fd);
}
