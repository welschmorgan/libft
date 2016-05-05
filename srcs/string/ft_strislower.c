/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strislower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:19:01 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/02 21:34:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strislower(char const *str)
{
	int						code;

	code = 0;
	if (str && *str)
	{
		code = 1;
		while (code && str && *str)
		{
			if (!ft_islower(*str++))
				code = 0;
		}
	}
	return (code);
}
