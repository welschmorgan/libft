/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 12:47:19 by mwelsch           #+#    #+#             */
/*   Updated: 2016/05/07 18:52:17 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnrot_l(char *str,
						  size_t n,
						  int count)
{
	while (count-- > 0)
		ft_strnrot_one_l(str, n);
	return (str);
}

char		*ft_strnrot_r(char *str,
						  size_t n,
						  int count)
{
	while (count-- > 0)
		ft_strnrot_one_r(str, n);
	return (str);
}

char		*ft_strnrot_one_l(char *str,
							  size_t n)
{
	char	*pcur;
	char	*pend;

	pcur = str;
	pend = str + n;
	while (pcur < pend && n--)
	{
		*pcur = *(pcur + 1);
		pcur++;
	}
	*pcur = 0;
	return (str);
}

char		*ft_strnrot_one_r(char *str,
							  size_t n)
{
	char	*pcur;
	char	*pend;

	pcur = str + n;
	pend = str;
	*pcur-- = 0;
	while (pcur > pend && n--)
	{
		*pcur = *(pcur - 1);
		pcur--;
	}
	return (pcur);
}
