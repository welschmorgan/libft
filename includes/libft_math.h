/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:46:41 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/15 12:57:57 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_MATH_H
# define	LIBFT_MATH_H

# define FT_PI					3.14159265359
# define FT_FLOAT_TOO_LARGE		1000
# define FT_FLOAT_TOO_SMALL		1001
# define FT_FLOAT_SIZE			15
# define FT_FLOAT_TOLERANCE		0.0000001
# define FT_FLOAT_PRECISION		6


double						ft_pow(double x, double y);
float						ft_powf(float x, float y);

typedef struct				s_log10
{
	unsigned int			level;
	unsigned int			value;
}							t_log10;
t_log10						*ft_log10_table();
unsigned int				ft_log10(unsigned int num);

typedef union				u_float_iee754_value
{
	long					l;
	float					f;
}							t_float_iee754_value;

typedef	struct				s_float_iee754
{
	long					mantissa;
	long					whole;
	long					decimal;
	short					exponent;
	int						precision;
	int						status;
	t_float_iee754_value	value;
	char					buffer[FT_FLOAT_SIZE];
	char					*offset;
}							t_float_iee754;

t_float_iee754				*ft_float_iee754_init(t_float_iee754 *f,
												  float v, int precision);
t_float_iee754				*ft_float_iee754_init_fiddle(t_float_iee754 *f);
t_float_iee754				*ft_float_iee754_init_fiddle_exp(t_float_iee754 *f);

char						*ft_float_iee754_string_whole(t_float_iee754 *f);
char						*ft_float_iee754_string_finalize(t_float_iee754 *f, char *dec);
char						*ft_float_iee754_string_decdo(t_float_iee754 *f, char *dec);
char						*ft_float_iee754_string_dec(t_float_iee754 *f);

void						ft_float_iee754_round(t_float_iee754 *f);
int							ft_float_iee754_len(t_float_iee754 *f);

char						*ft_float_iee754_string(t_float_iee754 *f);

int							ft_float_iee754_iszero(t_float_iee754 *f);
int							ft_float_iee754_cmp(t_float_iee754 *f, float to);

int							ft_floor(int n);

#endif
