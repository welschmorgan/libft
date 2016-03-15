/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:38:28 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 12:35:08 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"

static size_t const			g_vsnprintf_nhandlers = 8;

static t_vsnprintf_handler	g_vsnprintf_handlers[] =
{
	{2, {"s", "S"}, 0, ft_vsnprintf_handle_string},
	{3, {"i", "l", "d"}, 0, ft_vsnprintf_handle_signed},
	{1, {"f"}, 0, ft_vsnprintf_handle_float},
	{1, {"u"}, 0, ft_vsnprintf_handle_unsigned},
	{2, {"c", "C"}, 0, ft_vsnprintf_handle_char},
	{2, {"p", "P"}, 0, ft_vsnprintf_handle_pointer},
	{2, {"t", "T"}, 0, ft_vsnprintf_handle_bool},
	{2, {"x", "X"}, 0, ft_vsnprintf_handle_hexa},
};

t_vsnprintf_handler			*ft_vsnprintf_get_handler(char const *c)
{
	size_t				i;
	size_t				j;
	char				*trigger;
	t_vsnprintf_handler	*handler;

	i = 0;
	j = 0;
	while (i < g_vsnprintf_nhandlers)
	{
		j = 0;
		handler = &g_vsnprintf_handlers[i];
		handler->triggered = NULL;
		while (j < (size_t)handler->ntriggers)
		{
			trigger = handler->triggers[j];
			if (trigger && !ft_strncmp(c, trigger, ft_strlen(trigger)))
			{
				handler->triggered = trigger;
				return (handler);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void						ft_vsnprintf_handle_string(t_vsnprintf_env *env,
													va_list args)
{
	ft_vsnprintf_string(env, args, ft_isupper(*env->format));
}

void						ft_vsnprintf_handle_char(t_vsnprintf_env *env,
													va_list args)
{
	ft_vsnprintf_char(env, args, ft_isupper(*env->format));
}

void						ft_vsnprintf_handle_bool(t_vsnprintf_env *env,
													va_list args)
{
	ft_vsnprintf_bool(env, args, ft_isupper(*env->format));
}
