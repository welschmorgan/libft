/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:19:26 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/02 21:34:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strisupper(char const *str)
{
	int						code;

	code = 0;
	if (str && *str)
	{
		code = 1;
		while (code && str && *str)
		{
			if (!ft_isupper(*str))
				code = 0;
			str++;
		}
	}
	return (code);
}
