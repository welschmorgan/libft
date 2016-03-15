/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_converters.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 01:30:30 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 17:40:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERTERS_H
# define LIBFT_CONVERTERS_H

# include <string.h>
# include "libft_math.h"

char					*ft_itoa(int n);
char					*ft_ftoa(float n, int precision);
int						ft_atoi(const char *str);
long					ft_atol(const char *str);
size_t					ft_number_length(long num, int base);
char					*ft_ntoa(long num, int base);
int						get_float_decimal(float f, int precision);

#endif
