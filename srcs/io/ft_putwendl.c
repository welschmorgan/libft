/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:40:33 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/05 17:20:35 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int							ft_putwendl(wchar_t const *s)
{
	return (ft_putwendl_fd(s, 1));
}

int							ft_putwendl_fd(wchar_t const *str,
										  int fd)
{
	size_t					len;
	int						ret;

	len = ft_wstrlen(str);
	ret = ft_putwstr_fd(str, fd);
	if (str && str[len] != '\n')
		ret += ft_putwstr_fd(L"\n", fd);
	return (ret);
}
