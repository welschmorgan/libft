/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 20:48:11 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 11:37:08 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_float_iee754_iszero(t_float_iee754 *f)
{
	return (!ft_float_iee754_cmp(f, 0.0f));
}

int							ft_float_iee754_cmp(t_float_iee754 *f, float to)
{
	if (!f)
		return (-1);
	if (f
		&& f->value.f > (to - FT_FLOAT_TOLERANCE)
		&& f->value.f < (to + FT_FLOAT_TOLERANCE))
		return (0);
	if (f->value.f < (to - FT_FLOAT_TOLERANCE))
		return (-1);
	return (1);
}
