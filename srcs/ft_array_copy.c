/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:47:20 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:53:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_string.h>

t_array			*ft_array_copy(t_array *dst, t_array const *src,
						size_t n, t_bool keep_null)
{
	size_t		id;
	size_t		cur;

	id = 0;
	cur = 0;
	ft_array_clear(dst);
	ft_array_init(dst, src->capacity);
	while (id < src->capacity && id < n)
	{
		if (keep_null || src->data[id])
		{
			dst->data[cur] = ft_strdup(src->data[id]);
			cur++;
		}
		id++;
	}
	dst->size = cur;
	return (dst);
}

t_array			*ft_array_copy_raw(t_array *dst,
									char *const *src,
									size_t n, t_bool keep_null)
{
	size_t		id;
	size_t		cur;

	id = 0;
	cur = 0;
	ft_array_clear(dst);
	ft_array_init(dst, n);
	while (id < n)
	{
		if (keep_null || src[id])
		{
			if (src[id])
				dst->data[cur] = ft_strdup(src[id]);
			else
				dst->data[cur] = NULL;
			cur++;
		}
		id++;
	}
	dst->size = cur;
	return (dst);
}
