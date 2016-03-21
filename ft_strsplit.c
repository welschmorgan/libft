/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:45:01 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/21 12:40:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char sep)
{
	size_t		ret;

	ret = 0;
	while (s && *s)
	{
		if (*s == sep)
			ret++;
		while (*s == sep)
		{
			s++;
		}
		s++;
	}
	return (ret);
}

static size_t	ft_strlen_ptr(char const *start, char const *end)
{
	if (!end)
		return (ft_strlen(start));
	return (((unsigned char*)end - (unsigned char *)start));
}

static char		*trim_chars(char *ptr, char c)
{
	while (ptr && *ptr == c)
		ptr++;
	return (ptr);
}

static char		*trim_word(char *ptr, char c)
{
	while (ptr && (*ptr != c) && *ptr)
		ptr++;
	return (ptr);
}

char			**ft_strsplit(char const *s, char c)
{
	t_strsplit_env		env;

	if (!s)
		return (NULL);
	env.c = c;
	env.str = s;
	env.len = ft_count_words(env.str, c);
	env.ret = (char**)ft_memalloc(sizeof(char*) * (env.len + 1));
	env.ptr = (char*)env.str;
	env.p_ret = env.ret;
	while (env.ptr && *env.ptr)
	{
		env.ptr = trim_chars(env.ptr, env.c);
		env.orig = env.ptr;
		env.ptr = trim_word(env.ptr, env.c);
		env.len = ft_strlen_ptr(env.orig, env.ptr);
		if (env.orig && env.p_ret && *env.orig)
			*env.p_ret++ = ft_strsub(env.orig, 0, env.len);
		if (!*env.ptr)
			break ;
		env.ptr++;
	}
	*env.p_ret = NULL;
	return (env.ret);
}
