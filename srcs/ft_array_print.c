/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:42:47 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:43:06 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_printf.h>

void			ft_array_print(t_array const *a, t_bool long_fmt)
{
	size_t		id;
	static char	buf[1024] = {0};

	if (!long_fmt)
	{
		ft_printf("%s\n", ft_array_join(a, buf, 1024, ","));
	}
	else
	{
		if (!a->capacity)
		{
			ft_printf("array empty!\n");
			return ;
		}
		id = 0;
		while (id < a->capacity)
		{
			ft_printf("%s\n", a->data[id]);
			id++;
		}
	}
}
