/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:23:29 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 19:48:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>

size_t				ft_vsnprintf_loop(t_vsnprintf_env *env,
									va_list args)
{
	if (!env)
		return (0);
	while (env->format && *env->format)
	{
		if (*env->format == '%')
		{
			env->format++;
			env->width = ft_vsnprintf_extract_width(env);
			ft_vsnprintf_step(env, args);
		}
		else
		{
			*env->offset++ = *env->format;
			env->counter++;
			env->format++;
		}
	}
	return (env->counter);
}
