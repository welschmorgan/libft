/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:21:59 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 21:43:12 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

void				ft_vsnprintf_signed(t_vsnprintf_env *env,
										va_list args,
										int base)
{
	long		i;
	size_t		len;

	i = (long)va_arg(args, long);
	if (!env)
		return ;
	ft_strncpy(env->offset, ft_ntoa(i, base), env->max);
	if (env->width > 0)
		ft_strpad_l(env->offset, env->width, '0');
	len = ft_strlen(env->offset);
	env->counter += len;
	env->offset += len;
}
