
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:22:47 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 20:07:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

static long			ft_vsnprintf_hexa1(t_vsnprintf_env *env,
										long i,
										int caps)
{
	long				next;
	char				*str;
	size_t				len;

	next = i & 0xffff;
	str = ft_ntoa(i >> 16, 16);
	len = ft_strlen(str);
	ft_strncpy(env->offset,
			caps ? ft_strtoupper(str) : str,
			env->max);
	env->offset += len;
	env->counter += len;
	return (next);
}

static void				ft_vsnprintf_hexa2(t_vsnprintf_env *env,
										unsigned long next,
										int caps)
{
	char			*str;
	size_t			len;

	str = ft_ntoa(next, 16);
	len = ft_strlen(str);
	ft_strncpy(env->offset,
			caps ? ft_strtoupper(str) : str,
			env->max);
	env->offset += len;
	env->counter += len;
}

void					ft_vsnprintf_hexa(t_vsnprintf_env *env,
										va_list args,
										int caps,
										int ptr)
{
	long	i;
	long	next;
	char	*offset;
	int		cnt;

	i = (long)va_arg(args, long);
	if (!env)
		return ;
	next = i;
	offset = env->offset;
	cnt = env->counter;
	if (ptr)
		next = ft_vsnprintf_hexa1(env, i, caps);
	if (ptr && !next)
		return ;
	ft_vsnprintf_hexa2(env, next, caps);
	if (env->width > 0)
	{
		ft_strpad_l(offset, env->width, '0');
		env->offset = offset + env->width;
		env->counter = cnt + env->width;
	}
}
