/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:23:07 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 12:29:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>

void				ft_vsnprintf_step(t_vsnprintf_env *env,
									va_list args)
{
	t_vsnprintf_handler	*handler;

	handler = ft_vsnprintf_get_handler(env->format);
	if (handler)
	{
		handler->func(env, args);
		env->format += ft_strlen(handler->triggered);
	}
	else
	{
		*env->offset = *env->format;
		env->offset++;
		env->counter++;
		env->format++;
	}
}
