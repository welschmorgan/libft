/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:00:37 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 15:28:50 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

# include <string.h>
# include <libft_types.h>

# define NPOS							((size_t)-1)

typedef struct			s_array
{
	size_t				size;
	size_t				capacity;
	char				**data;
}						t_array;

typedef struct			s_array_joiner
{
	t_array const		*array;
	char				*buf;
	char const			*sep;
	size_t				n;
	size_t				id;
	size_t				cur;
	t_bool				first;
	size_t				len;
}						t_array_joiner;

t_array_joiner			ft_array_joiner_init(t_array const *a, char *buf,
											size_t n,
											char const *sep);

t_array					*ft_array_copy_raw(t_array *dst,
											char *const *s,
											size_t n,
											t_bool kp_null);
t_array					*ft_array_copy(t_array *dst,
										t_array const *src,
										size_t n,
										t_bool keep_null);
t_array					*ft_array_init(t_array *a,
										size_t len);
t_array					*ft_array_clear(t_array *a);
t_array					*ft_array_unset(t_array *dst,
										size_t id);
size_t					ft_array_append(t_array *a,
										char const *val);
char					*ft_array_set(t_array *dst, size_t id,
									char const *value);
char					*ft_array_join(t_array const *a,
										char *buf,
										size_t n,
										char const *sep);
void					ft_array_print(t_array const *a,
										t_bool long_fmt);
size_t					ft_array_find(t_array const *a,
									char const *key);
size_t					ft_array_find_sep(t_array const *array,
										char const *name,
										char sep);
int						ft_array_iter(t_array *a,
										int (*pfn)(char *));

#endif
