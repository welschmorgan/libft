/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:27:50 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/29 08:29:38 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <errno.h>
#include <libft_file.h>
#include <libft_printf.h>

t_bool				ft_file_executable(const char *path)
{
	return (ft_file_access(path, X_OK));
}

t_bool				ft_file_access(const char *path, int access_mode)
{
	if (access(path, access_mode))
	{
#ifdef FT_DEBUG_FILESYSTEM
		if (errno == EACCES)
			ft_error("%s: file not executable '%s'\n", __FUNCTION__, path);
		else if (errno == ENOENT)
			ft_error("%s: file doesn't exist '%s'\n",
					 __FUNCTION__, path);
		else if (errno == EROFS)
			ft_error("%s: write permission requested on a read only filesystem",
					 __FUNCTION__, path);

#endif
		return (FALSE);
	}
	return (TRUE);
}
