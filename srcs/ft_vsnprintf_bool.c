/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_bool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:50:15 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 10:50:16 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_vsnprintf_bool(t_vsnprintf_env *env,
											va_list args,
											int upper)
{
	int					b;
	size_t				len;
	char				buf[6];

	if (!env)
		return ;
	b = (int)va_arg(args, int);
	ft_strncpy(buf, b != 0 ? "true" : "false", 6);
	len = ft_strlen(buf);
	env->counter += len;
	if (env->counter < env->max)
		ft_strncpy(env->offset, upper ? ft_strtoupper(buf) : buf, len);
	env->offset += len;
}
