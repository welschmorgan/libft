/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 04:21:13 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 12:30:46 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

void			ft_vsnprintf_float(t_vsnprintf_env *env,
								va_list args)
{
	double		f;
	size_t		len;

	f = (double)va_arg(args, double);
	if (!env)
		return ;
	ft_strncpy(env->offset,
			ft_ftoa(f,
					env->width > 0
					? env->width
					: FT_FLOAT_PRECISION),
			env->max);
	len = ft_strlen(env->offset);
	env->offset += len;
	env->counter += len;
}
