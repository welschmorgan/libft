/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isanyof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:10:28 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/30 15:11:48 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isanyof(char c, char const *seps)
{
	while (seps && *seps)
	{
		if (c == *(seps++))
			return (TRUE);
	}
	return (FALSE);
}
