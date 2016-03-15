/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_extract_width.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:30:51 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 11:55:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_memory.h"
#include "libft_string.h"
#include "libft_converters.h"

int					ft_vsnprintf_extract_width(t_vsnprintf_env *env)
{
	char			wstr[32];
	size_t			pos;

	if (!env)
		return (0);
	pos = 0;
	ft_memset(wstr, 0, 32);
	while (env->format && *env->format
		&& ft_isdigit(*env->format)
		&& pos < 32)
		wstr[pos++] = *env->format++;
	wstr[pos] = 0;
	return (ft_atoi(wstr));
}
