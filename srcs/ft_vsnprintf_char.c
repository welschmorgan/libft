/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:21:02 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/14 16:30:25 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>

void				ft_vsnprintf_char(t_vsnprintf_env *env,
									va_list args,
									int caps)
{
	char			c;
	size_t			len;

	c = (char)va_arg(args, int);
	if (!env)
		return ;
	len = env->width;
	len = len ? len : (c != 0);
	while (len-- && (env->counter < env->max))
	{
		*env->offset = caps ? ft_toupper(c) : c;
		env->counter++;
		env->offset++;
	}
}
