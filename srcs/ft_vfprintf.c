/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:14:33 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 18:07:34 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_string.h>

int				ft_vfprintf(int fd, const char *fmt, va_list args)
{
	static char	buf[1024] = {0};
	int			ret;

	ret = ft_vsnprintf(buf, 1024, fmt, args);
	ft_putstr_fd(buf, fd);
	return (ret);
}

/*	int		ret;
	char	*sptr;

	sptr = (char*)fmt;
	ret = 0;
	while (sptr && *sptr)
	{
		ret += ft_parse_printf_char(fd, &sptr, args);
		sptr++;
	}
	return (ret);
*/
