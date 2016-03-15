/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:59:02 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 15:26:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"
#include <stdarg.h>

static void				padded_print(t_padded_print *print)
{
	char			*s;
	char			*ntoa;

	ntoa = ft_ntoa(print->num, print->base);
	ntoa = print->caps ? ft_strtoupper(ntoa) : ntoa;
	if (!print->width)
		s = ft_strdup(ntoa);
	else
		s = ft_strndup(ntoa, print->width);
	if (ft_strlen(s) < print->width)
	{
		print->width -= ft_strlen(s);
		while (--print->width)
			*print->counter += ft_putchar_fd('0', print->fd);
	}
	*print->counter += ft_putstr_fd(s, print->fd);
	ft_strdel(&s);
}

void					ft_printf_do_number(t_printf_parse_env *env,
											va_list args,
											int base,
											int caps)
{
	t_uint				u;
	t_padded_print		print;

	u = va_arg(args, t_uint);
	print.fd = env->fd;
	print.num = u;
	print.base = base;
	print.width = env->width;
	print.counter = &env->ret;
	print.caps = caps;
	padded_print(&print);
}
