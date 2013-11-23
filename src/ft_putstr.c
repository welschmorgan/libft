/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:30:15 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/23 21:31:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char const *str)
{
	if (!str)
		write(1, INVALID_STR, ft_strlen(INVALID_STR));
	else
		write(1, str, ft_strlen(str));
}
