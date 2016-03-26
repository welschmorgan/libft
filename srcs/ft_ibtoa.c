/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ibtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:40:26 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned		ft_ibtoa_len(t_ibtoa *n)
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

static t_ibtoa		*ft_ibtoa_init(t_ibtoa *n, int num, unsigned base)
{
	static char const	range[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	unsigned			range_len;

	range_len = ft_strlen(range);
	n->sign = num < 0 ? -1 : 1;
	n->num = num * n->sign;
	n->base = base > range_len ? range_len : base;
	n->range = &range[0];
	n->div = n->num;
	n->mod = n->div % n->base;
	n->cur = 0;
	n->len = ft_ibtoa_len(n);
	n->buf = ft_strnew(n->len);
	if (n->buf)
	{
		n->pbuf = &n->buf[0] + n->len;
		*n->pbuf-- = 0;
	}
	return (n);
}

static t_ibtoa		*ft_ibtoa_do(t_ibtoa *n)
{
	n->div = n->num;
	n->mod = n->div % n->base;
	if (!n->num)
	{
		*n->pbuf-- = 0;
		*n->pbuf = '0';
		return (n);
	}
	while (n->div > 0 && n->cur <= n->len)
	{
		*n->pbuf-- = n->range[n->mod];
		n->div /= n->base;
		n->mod = n->div % n->base;
	}
	if (n->sign < 0)
		*n->pbuf-- = '-';
	n->pbuf++;
	return (n);
}

char				*ft_ibtoa(int n, unsigned base)
{
	t_ibtoa	env;
	char	*ret;

	ft_ibtoa_init(&env, n, base);
	if (!env.buf)
		return (env.buf);
	ft_ibtoa_do(&env);
	ret = ft_strdup(env.pbuf);
	ft_strdel(&env.buf);
	return (ret);
}
