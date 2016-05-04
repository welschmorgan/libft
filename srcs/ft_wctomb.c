/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:29:04 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/02 01:01:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_wctomb_21(unsigned char **b, wchar_t c)
{
	**b = (unsigned char)(((c>>18))|0xF0);
	*b += 1;
	**b = (unsigned char)(((c>>12)&0x3F)|0x80);
	*b += 1;
	**b = (unsigned char)(((c>>6)&0x3F)|0x80);
	*b += 1;
	**b = (unsigned char)((c&0x3F)|0x80);
	*b += 1;
}

static void			ft_wctomb_16(unsigned char **b, wchar_t c)
{
	**b = (unsigned char)(((c>>12))|0xE0);
	*b += 1;
	**b =  (unsigned char)(((c>>6)&0x3F)|0x80);
	*b += 1;
	**b =  (unsigned char)((c&0x3F)|0x80);
	*b += 1;
}

static void			ft_wctomb_11(unsigned char **b, wchar_t c)
{
	**b = (unsigned char)((c>>6)|0xC0);
	*b += 1;
	**b = (unsigned char)((c&0x3F)|0x80);
	*b += 1;
}

static void			ft_wctomb_7(unsigned char **b, wchar_t c)
{
	**b = (unsigned char)(c);
	*b += 1;
}

const char			*ft_wctomb(wchar_t c)
{
	static unsigned char b_static[5];
	unsigned char* b = b_static;

	if (c < (1 << 7))// 7 bit Unicode encoded as plain ascii
		ft_wctomb_7(&b, c);
	else if (c < ( 1 << 11))// 11 bit Unicode encoded in 2 UTF-8 bytes
		ft_wctomb_11(&b, c);
	else if (c < (1 << 16))// 16 bit Unicode encoded in 3 UTF-8 bytes
		ft_wctomb_16(&b, c);
	else if (c < (1 << 21))// 21 bit Unicode encoded in 4 UTF-8 bytes
		ft_wctomb_21(&b, c);
	*b = '\0';
	return ((const char*)&b_static[0]);
}
