/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ibtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:40:26 by mwelsch           #+#    #+#             */
/*   Updated: 2016/04/30 17:45:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned		ft_ubtoa_len(t_ubtoa *n)
{
	n->len = 0;
	n->div = n->num;
	n->mod = n->div % n->base;
	if (!n->num)
	{
		n->len = 1;
		return (n->len);
	}
	while (n->div > 0)
	{
		n->len++;
		n->div /= n->base;
		n->mod = n->div % n->base;
	}
	n->len += n->sign < 0 ? 1 : 0;
	return (n->len);
}

static t_ubtoa		*ft_ubtoa_init(t_ubtoa *n, unsigned num, unsigned base)
{
	static char const	range[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	unsigned			range_len;

	range_len = ft_strlen(range);
	n->sign = 1;
	n->num = num * n->sign;
	n->base = base > range_len ? range_len : base;
	n->range = &range[0];
	n->div = n->num;
	n->mod = n->div % n->base;
	n->cur = 0;
	n->len = ft_ubtoa_len(n);
	n->buf = ft_strnew(n->len);
	n->pbuf = NULL;
	if (n->buf)
		n->pbuf = &n->buf[n->len - 1];
	return (n);
}

static t_ubtoa		*ft_ubtoa_do(t_ubtoa *n)
{
	n->div = n->num;
	n->mod = n->div % n->base;
	if (!n->num)
	{
		*n->pbuf-- = '0';
	}
	else
	{
		while (n->div > 0 && n->cur <= n->len)
		{
			*n->pbuf-- = n->range[n->mod];
			n->div /= n->base;
			n->mod = n->div % n->base;
		}
		if (n->sign < 0)
			*n->pbuf-- = '-';
	}
	n->pbuf++;
	return (n);
}

char				*ft_ubtoa(unsigned n, unsigned base)
{
	t_ubtoa	env;
	char	*ret;

	ft_ubtoa_init(&env, n, base);
	if (!env.buf)
		return (env.buf);
	ft_ubtoa_do(&env);
	ret = ft_strdup(env.pbuf);
	ft_strdel(&env.buf);
	return (ret);
}
