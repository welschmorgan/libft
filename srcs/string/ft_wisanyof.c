/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wisanyof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:40:19 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 20:40:28 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_wisanyof(wchar_t c,
										wchar_t const *seps)
{
	while (seps && *seps && c != *seps)
		seps++;
	return (seps && *seps && c == *seps);
}
