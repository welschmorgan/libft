/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dnode_new_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:02:05 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:33:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"
#include "libft_string.h"

t_dnode				*ft_dnode_new_str(char const *str, unsigned int flags)
{
	return (ft_dnode_new_strn(str,
							ft_strlen(str),
							flags));
}

t_dnode				*ft_dnode_new_strn(char const *str,
									size_t const n,
									unsigned int flags)
{
	return (ft_dnode_new((void*)str,
						sizeof(char) * n,
						flags));
}
