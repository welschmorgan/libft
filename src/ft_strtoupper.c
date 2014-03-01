/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 00:59:34 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 12:02:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_string.h"

char					*ft_strtoupper(char *s)
{
	char				*start;

	start = s;
	while (s && *s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return (start);
}
