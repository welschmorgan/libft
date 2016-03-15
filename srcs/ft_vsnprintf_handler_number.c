/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_handler_number.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:41:27 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 15:16:47 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"

void				ft_vsnprintf_handle_signed(t_vsnprintf_env *env,
											va_list args)
{
	ft_vsnprintf_signed(env, args, 10);
}

void				ft_vsnprintf_handle_float(t_vsnprintf_env *env,
											va_list args)
{
	ft_vsnprintf_float(env, args);
}

void				ft_vsnprintf_handle_unsigned(t_vsnprintf_env *env,
												va_list args)
{
	ft_vsnprintf_unsigned(env, args, 10);
}

void				ft_vsnprintf_handle_pointer(t_vsnprintf_env *env,
											va_list args)
{
	ft_strncpy(env->offset, "0x", env->max);
	env->offset += 2;
	env->counter += 2;
	ft_vsnprintf_hexa(env, args, ft_isupper(*env->format), 1);
}

void				ft_vsnprintf_handle_hexa(t_vsnprintf_env *env,
										va_list args)
{
	ft_vsnprintf_hexa(env, args, ft_isupper(*env->format), 0);
}
