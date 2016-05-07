/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:06:56 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/07 13:07:04 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <values.h>


char				ft_bit(const char *value,
						   size_t elem_size,
						   int bit)
{
	char			bval;

	if (ft_endian() == ENDIAN_LITTLE)
		bval = value[bit / CHARBITS];
	else
		bval = value[elem_size - bit / CHARBITS - 1];
	return ((bval >> (bit % CHARBITS)) & 0x01);
}
