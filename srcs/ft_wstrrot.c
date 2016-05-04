/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 21:40:00 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/01 21:41:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrnrot_l(wchar_t *str,
						  size_t n,
						  int count)
{
	while (count-- > 0)
		ft_wstrnrot_one_l(str, n);
	return (str);
}

wchar_t		*ft_wstrnrot_r(wchar_t *str,
						  size_t n,
						  int count)
{
	while (count-- > 0)
		ft_wstrnrot_one_r(str, n);
	return (str);
}

wchar_t		*ft_wstrnrot_one_l(wchar_t *str,
							  size_t n)
{
	wchar_t	*pcur;
	wchar_t	*pend;

	pcur = str;
	pend = str + n;
	while (pcur < pend && n--)
	{
		*pcur = *(pcur + 1);
		pcur++;
	}
	return (str);
}

wchar_t		*ft_wstrnrot_one_r(wchar_t *str,
							  size_t n)
{
	wchar_t	*pcur;
	wchar_t	*pend;

	pcur = str + n;
	pend = str;
	while (pcur > pend && n--)
	{
		*pcur = *(pcur - 1);
		pcur--;
	}
	return (str);
}
