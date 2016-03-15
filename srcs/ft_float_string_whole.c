/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_string_whole.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:01:11 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 13:02:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"
#include "libft_string.h"
#include "libft_converters.h"

char						*ft_float_iee754_string_whole(t_float_iee754 *f)
{
	char					*num;
	int						len;

	f->offset = f->buffer;
	if (ft_float_iee754_iszero(f))
		return (ft_strcpy(f->offset++, "0"));
	if (f->value.f <= -FT_FLOAT_TOLERANCE)
		*f->offset++ = '-';
	if (f->whole == 0)
		*f->offset++ = '0';
	else
	{
		num = ft_ntoa(f->whole, 10);
		len = ft_strlen(num);
		ft_strncpy(f->offset, num, FT_FLOAT_SIZE);
		f->offset += len;
	}
	return (f->buffer);
}
