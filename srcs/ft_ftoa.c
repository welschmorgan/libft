/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:49:31 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/11 20:20:08 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char						*ft_ftoa(float num, int prec)
{
	static t_float_iee754	f;

	ft_memset(&f, 0, sizeof(t_float_iee754));
	ft_float_iee754_init(&f, num, prec);
	if (f.status == FT_FLOAT_TOO_LARGE
		|| f.status == FT_FLOAT_TOO_SMALL)
		ft_strncpy(f.buffer, "nan", FT_FLOAT_SIZE);
	else
		ft_float_iee754_string(&f);
	return (f.buffer);
}
