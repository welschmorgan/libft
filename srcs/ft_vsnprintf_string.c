/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:21:37 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 19:48:55 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_string.h>
#include <libft_printf.h>

void				ft_vsnprintf_string(t_vsnprintf_env *env,
										va_list args,
										int caps)
{
	char			*s;
	size_t			len;

	s = (char*)va_arg(args, char*);
	if (!s || !env)
		return ;
	len = ft_strlen(s);
	s = caps ? ft_strtoupper(s) : s;
	ft_strncpy(env->offset, s, env->max);
	if (env->width)
	{
		len = (size_t)env->width;
		ft_strpad_r(env->offset, env->width, ' ');
	}
	env->counter += len;
	env->offset += len;
}
