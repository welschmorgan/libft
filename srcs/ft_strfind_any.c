/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:20:02 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:05:37 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

int					ft_strfind_any(char *str,
								char const *seps,
								int offset)
{
	int				found;

	found = -1;
	if (!str || !seps)
		return (found);
	while (seps && *seps && (found = ft_strfind(str, *seps, offset)) == -1)
		seps++;
	return (found);
}
