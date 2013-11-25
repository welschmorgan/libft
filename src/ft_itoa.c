/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:20:16 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/24 21:34:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_size(int dig)
{
	int			ret;
	int			temp;

	temp = dig;
	while (temp)
	{
		ret++;
		temp /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char*	ret;
	int		num_chars;
	int		negative;

	negative = 0;
	num_chars = 0;
	ret = NULL;
	if (n < 0)
	{
		n = -n;
		negative = 1;
		num_chars++;
	}
	num_chars += ft_nbr_size(n);
	ret = ft_strnew(num_chars + 1);
	ret[num_chars] = '\0';
 
	if (negative)
		ret[0] = '-';
 
	int i = num_chars - 1;
	while (n)
	{
		ret[i--] = n%10 + '0';
		n /= 10;
	}
 
	return ret;
}
