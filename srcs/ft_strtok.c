/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:15:45 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 15:15:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_memory.h"

static void			ft_strtok_pass(char **ret, char *str, int len,
								char const *seps)
{
	int				pos;
	int				last;
	size_t			id;

	id = 0;
	last = 0;
	pos = 0;
	while ((pos = ft_strfind_any(str, seps, last)) != -1
		&& pos < (int)ft_strlen(str))
	{
		ret[id] = ft_strnew((pos - 1) - last + 1);
		ft_strncpy(ret[id++], str + last, (pos - 1) - last);
		last = pos;
	}
	if (len - last > 0)
	{
		ret[id] = ft_strnew(len - last);
		ft_strncpy(ret[id++], str + last, len - last);
	}
	ret[id] = NULL;
}

char				**ft_strtok(char *str,
								char const *seps)
{
	char			**ret;
	int				len;

	len = (int)ft_strlen(str);
	ret = ft_memalloc(sizeof(char*) * FT_TOK_MAX);
	ft_strtok_pass(ret, str, len, seps);
	return (ret);
}
