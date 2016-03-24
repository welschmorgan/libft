/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dnode_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:03:17 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 15:01:28 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"
#include "libft_string.h"
#include "libft_printf.h"
#include "libft_memory.h"

char				*ft_dnode_flag_name(t_dnode_flag flag)
{
	static char		buf[32] = {0};

	ft_strncpy(buf, "destroy_nothing", 32);
	if (flag == NF_DESTROY_DATA)
		ft_strncpy(buf, "destroy_data", 32);
	else if (flag == NF_DESTROY_NODE)
		ft_strncpy(buf, "destroy_node", 32);
	return (buf);
}

char				*ft_dnode_flag_str(t_dnode *node)
{
	static char		buf[255] = {0};
	size_t			offs;

	if (!node)
	{
		ft_strncpy(buf, "NULL", 255);
		return (buf);
	}
	offs = 0;
	ft_bzero(buf, 255);
	offs = ft_strlen(buf);
	ft_snprintf(buf, 255 - offs, "%s%s", (offs ? "|" : ""), "data");
	offs = ft_strlen(buf);
	ft_snprintf(buf, 255 - offs, "%s%s", (offs ? "|" : ""), "node");
	return (buf);
}
