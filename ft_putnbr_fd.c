/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:39:21 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/19 13:40:17 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int num, int fd)
{
	char	*str;

	str = ft_itoa(num);
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
}
