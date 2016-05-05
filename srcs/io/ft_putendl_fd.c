/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:38:03 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:12:43 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = 0;
	len += ft_putstr_fd(s, fd);
	len += ft_putstr_fd("\n", fd);
	return (len);
}
