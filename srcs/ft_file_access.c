/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:27:50 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:34:25 by mwelsch          ###   ########.fr       */
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
		return (FALSE);
	return (TRUE);
}
