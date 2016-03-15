/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:04:57 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 14:27:08 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_string.h>
#include "unistd.h"

int				ft_readline(int fd, char *buf, size_t buf_max)
{
	int			bread;
	char		cap;
	char		*ptr;
	size_t		cur_len;

	if (!buf)
		return (-1);
	cur_len = 0;
	ptr = buf;
	while (cur_len < buf_max)
	{
		bread = read(fd, &cap, 1);
		if (bread < 0)
			return (bread);
		else if (!bread || cap == '\n')
		{
			*ptr = '\0';
			return (bread);
		}
		else
			*ptr = cap;
		cur_len += bread;
		ptr += bread;
	}
	return (0);
}
