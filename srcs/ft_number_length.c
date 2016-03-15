/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:48:23 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 17:43:57 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_converters.h"
#include "libft_string.h"

size_t	ft_number_length(long num, int base)
{
	char			*ptr;

	ptr = ft_ntoa(num, base);
	return (ft_strlen(ptr));
}
