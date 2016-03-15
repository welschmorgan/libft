/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:38:33 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/28 05:02:05 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putstr_fd(char const *str, int fd)
{
	if (!str)
		return (write(fd, FT_INVALID_STR, ft_strlen(FT_INVALID_STR)));
	return (write(fd, str, ft_strlen(str)));
}
