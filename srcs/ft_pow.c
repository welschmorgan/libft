/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:17:52 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 12:21:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

float		ft_powf(float x, float y)
{
	float	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if ((((long)y) % 2) == 0)
		return (temp * temp);
	else if (y > 0)
		return (x * temp * temp);
	return ((temp * temp) / x);
}

double		ft_pow(double x, double y)
{
	double	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if ((((long)y) % 2) == 0)
		return (temp * temp);
	else if (y > 0)
		return (x * temp * temp);
	return ((temp * temp) / x);
}
