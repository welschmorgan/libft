/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:27:03 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 11:10:43 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_sep(char const *s, char const *seps)
{
	char	*dup;

	dup = ft_strdup(s);
	if (!dup || !seps)
		return (dup);
	return (ft_strltrim(ft_strrtrim(dup, seps), seps));
}
