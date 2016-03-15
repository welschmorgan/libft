/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 02:15:22 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 12:23:47 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <libft_config.h>

# define FT_PRINTF_MAX_WIDTH		64
# define FT_VPRINTF_MAX_TRIGGERS	20

typedef struct			s_printf_parse_env
{
	int					fd;
	char				**fmt;
	int					ret;
	int					width;
}						t_printf_parse_env;

typedef struct			s_padded_print
{
	int					fd;
	t_uint				num;
	int					base;
	size_t				width;
	int					*counter;
	int					caps;
}						t_padded_print;

typedef struct			s_vsnprintf_env
{
	const char			*format;
	char				*buffer;
	char				*offset;
	size_t				max;
	size_t				counter;
	int					width;
}						t_vsnprintf_env;

typedef void			(*t_vsnprintf_func)(t_vsnprintf_env	*,
											va_list args);

typedef struct			s_vsnprintf_handler
{
	int					ntriggers;
	char				triggers[FT_VPRINTF_MAX_TRIGGERS][10];
	char const			*triggered;
	t_vsnprintf_func	func;
}						t_vsnprintf_handler;

int						ft_printf(const char *fmt, ...);
int						ft_vfprintf(int fd, const char *fmt, va_list argp);
size_t					ft_vsnprintf(char *buffer,
									size_t max,
									const char *fmt,
									va_list args);
size_t					ft_snprintf(char *buffer,
									size_t max,
									const char *fmt,
									...);
int						ft_fprintf(int fd, const char *fmt, ...);
int						ft_vprintf(const char *fmt, va_list argp);
int						ft_error(const char *fmt, ...);

t_vsnprintf_handler		*ft_vsnprintf_get_handler(char const *c);
int						ft_printf_parse_width(char **fmt);
void					ft_printf_do_char(t_printf_parse_env *env,
										va_list args);
void					ft_printf_do_string(t_printf_parse_env *env,
											va_list args);
void					ft_printf_do_bool(t_printf_parse_env *env,
										va_list args);
void					ft_printf_do_int(t_printf_parse_env *env,
										va_list args);
void					ft_printf_do_number(t_printf_parse_env *env,
											va_list args,
											int base,
											int caps);
void					ft_printf_do_pointer(t_printf_parse_env *env,
											va_list args,
											int caps);
void					ft_printf_do_char(t_printf_parse_env *env,
										va_list args);
int						ft_parse_printf_char(int fd,
											char **fmt,
											va_list args);

void					ft_vsnprintf_char(t_vsnprintf_env *env,
										va_list args,
										int caps);
void					ft_vsnprintf_float(t_vsnprintf_env *env,
										va_list args);
void					ft_vsnprintf_string(t_vsnprintf_env *env,
											va_list args,
											int caps);
void					ft_vsnprintf_signed(t_vsnprintf_env *env,
											va_list args,
											int base);
void					ft_vsnprintf_bool(t_vsnprintf_env *env,
											va_list args,
											int upper);
void					ft_vsnprintf_unsigned(t_vsnprintf_env *env,
											va_list args,
											int base);
void					ft_vsnprintf_hexa(t_vsnprintf_env *env,
										va_list args,
										int caps,
										int ptr);
void					ft_vsnprintf_step(t_vsnprintf_env *env,
										va_list args);
size_t					ft_vsnprintf_loop(t_vsnprintf_env *env,
										va_list args);
int						ft_vsnprintf_extract_width(t_vsnprintf_env *env);

void					ft_vsnprintf_handle_string(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_signed(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_float(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_bool(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_unsigned(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_char(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_pointer(t_vsnprintf_env *env,
												va_list args);
void					ft_vsnprintf_handle_hexa(t_vsnprintf_env *env,
												va_list args);

#endif
