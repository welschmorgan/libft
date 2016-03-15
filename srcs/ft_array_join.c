/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:43:38 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 14:58:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_string.h>

t_array_joiner	ft_array_joiner_init(t_array const *a, char *buf, size_t n,
										char const *sep)
{
	t_array_joiner	jnr;

	jnr.array = a;
	jnr.buf = buf;
	jnr.sep = sep;
	jnr.n = n;
	jnr.id = 0;
	jnr.cur = 0;
	jnr.first = TRUE;
	ft_strclr(buf);
	return (jnr);
}

static int		ft_array_join_pass(t_array_joiner *jnr)
{
	if (jnr->array->data[jnr->id])
	{
		jnr->len = ft_strlen(jnr->array->data[jnr->id]);
		if (jnr->cur + jnr->len >= jnr->n)
			return (0);
		if (!jnr->first)
		{
			ft_strncpy(jnr->buf + jnr->cur, jnr->sep, jnr->n - jnr->cur);
			ft_strncpy(jnr->buf + jnr->cur + ft_strlen(jnr->sep),
					jnr->array->data[jnr->id],
					jnr->n - (jnr->cur + ft_strlen(jnr->sep)));
		}
		else
		{
			ft_strncpy(jnr->buf + jnr->cur, jnr->array->data[jnr->id],
					jnr->n - jnr->cur);
		}
		jnr->cur += jnr->len
			+ (jnr->first ? 0 : ft_strlen(jnr->sep));
		jnr->first = FALSE;
	}
	jnr->id++;
	return (1);
}

char			*ft_array_join(t_array const *a, char *buf, size_t n,
							char const *sep)
{
	t_array_joiner	jnr;

	jnr = ft_array_joiner_init(a, buf, n, sep);
	while (jnr.id < jnr.array->capacity)
	{
		if (!ft_array_join_pass(&jnr))
			break ;
	}
	jnr.len = ft_strlen(buf);
	if (jnr.cur + jnr.len >= jnr.n && jnr.len >= 5)
	{
		ft_strncpy(jnr.buf + jnr.len - 5, "[...]", 5);
	}
	else
	{
		jnr.buf[jnr.cur] = '\0';
	}
	return (jnr.buf);
}
