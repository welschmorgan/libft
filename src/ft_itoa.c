/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:20:16 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/24 21:00:55 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incluce "libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;

	str = ft_strnew(64);
	sign = (value < 0);
	i = 0;
	if (value == 0)
		*(str++) = '0';
	else if (value < 0)
	{
		*(str++) = '-';
		value = -1;
	}
	while (value > 0)
	{
		*(str++) = '0' + (n % 10);
		n /= 10;
	}
	*str = '\0';
	return (str);
}
