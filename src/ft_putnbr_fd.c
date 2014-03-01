/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:39:21 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/23 01:43:26 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int num, int fd)
{
	int		ret;
	char	*str;

	str = ft_itoa(num);
	ret = ft_putstr_fd(str, fd);
	ft_strdel(&str);
	return (ret);
}
