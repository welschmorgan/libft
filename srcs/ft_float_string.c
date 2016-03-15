/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:03:27 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 13:03:27 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"
#include "libft_string.h"
#include "libft_converters.h"

char						*ft_float_iee754_string_finalize(t_float_iee754 *f,
															char *dec)
{
	while ((f->precision > 0
			? (*dec >= f->precision)
			: (*dec >= FT_FLOAT_PRECISION))
		&& ft_strncmp(f->offset - 1, ".0", 2))
	{
		--*dec;
		--f->offset;
	}
	++f->offset;
	++*dec;
	ft_strnround(f->buffer, ft_strlen(f->buffer),
				(f->offset - f->buffer) / sizeof(char));
	return (f->buffer);
}

char						*ft_float_iee754_string(t_float_iee754 *f)
{
	ft_float_iee754_string_whole(f);
	ft_float_iee754_string_dec(f);
	return (f->buffer);
}
