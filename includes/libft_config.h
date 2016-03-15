/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:30:15 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:02:34 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONFIG_H
# define LIBFT_CONFIG_H

# include <string.h>
# include "libft_version.h"
# include "libft_types.h"
# include "libft_platform.h"

# if defined(_DEBUG) && !defined(NDEBUG)
#  define LIBFT_DEBUG
#  define FT_DEBUG
# else
#  define LIBFT_RELEASE
#  define FT_RELEASE
# endif

# define FT_INVALID_STR "(null)"
# define FT_WHITESPACE_SEPS " \n\v\f\t"

/*
** CORE CONFIG
*/

# define FT_USE_PRINTF
# define FT_USE_FILESYSTEM
# define FT_USE_STRINGS
# define FT_USE_LINKED_LISTS

# ifdef FT_DEBUG
#  ifdef FT_USE_FILESYSTEM
#   define FT_DEBUG_FILESYSTEM
#  endif
#  ifdef FT_USE_STRINGS
#   define FT_DEBUG_STRING
#  endif
#  ifdef FT_USE_PRINTF
#   define FT_DEBUG_PRINTF
#  endif
#  ifdef FT_USE_LINKED_LISTS
#   define FT_DEBUG_LINKED_LISTS
#  endif
# endif

# define FT_BUF_MAX		4096
# define FT_TOK_MAX		1024
# define FT_PATH_MAX	260

# define FT_EPSILON		0.000001

# define FT_DEG2RAD(d) ((d) * (M_PI / 180.0))
# define FT_ABS(a)	(a < 0 ? (a * -1) : a)
# define FT_MIN(a, b)	(a < b ? a : b)
# define FT_MAX(a, b)	(a > b ? a : b)
# define FT_SIGN(a) (a < 0 ? -1 : 1)
# define FT_CLAMP(num, min, max) FT_MIN(FT_MAX(num, min), max)

#endif
