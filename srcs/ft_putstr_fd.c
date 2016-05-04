/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:38:33 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:06:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int			ft_putstr_fd(char const *str, int fd)
{
	int		len;

	len = 0;
	if (!str)
		len += write(fd, FT_INVALID_STR, ft_strlen(FT_INVALID_STR));
	else
		len += write(fd, str, ft_strlen(str));
	return(len);
}
