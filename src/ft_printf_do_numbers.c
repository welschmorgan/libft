/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:59:02 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/12 16:26:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"
#include <stdarg.h>

static void				padded_print(int fd,
									 t_uint num,
									 int base,
									 size_t width,
									 int *counter,
									 int caps)
{
	char			*s;
	char			*ntoa;

	ntoa = ft_ntoa(num, base);
	ntoa = caps ? ft_strtoupper(ntoa) : ntoa;
	if (!width)
		s = ft_strdup(ntoa);
	else
		s = ft_strndup(ntoa, width);
	if (ft_strlen(s) < width)
	{
		width -= ft_strlen(s);
		while (--width)
			*counter += ft_putchar_fd('0', fd);
	}
	*counter += ft_putstr_fd(s, fd);
	ft_strdel(&s);
}

void				ft_printf_do_number(t_printf_parse_env *env,
										va_list args,
										int base,
										int caps)
{
	t_uint			u;

	u = va_arg(args, t_uint);
	padded_print(env->fd, u, base, env->width, &env->ret, caps);
}
