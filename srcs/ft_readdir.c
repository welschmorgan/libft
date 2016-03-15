/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:10:49 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 14:26:40 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <dirent.h>
#include <errno.h>

struct dirent		*ft_readdir(DIR *handle)
{
	struct dirent	*ent;

	if (!(ent = readdir(handle)))
	{
		if (errno == EOVERFLOW)
			ft_error("%s: one of the values in the structure to be returned, "
					"cannot be represented correctly.\n",
					__FUNCTION__);
		else if (errno == EBADF)
			ft_error("%s: the dir handle does not refer to an open "
					"directory stream.\n", __FUNCTION__);
		else if (errno == ENOENT)
			ft_error("%s: the current position of the directory "
					"stream is invalid.\n", __FUNCTION__);
	}
	return (ent);
}
