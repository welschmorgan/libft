/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:37:56 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/24 20:40:12 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*pcur;
	char	*pend;

	pcur = str;
	pend = str + (ft_strlen(str) - 1);
	if (!*str)
		return (str);
	while (pcur != pend)
	{
		ft_swap(pcur, pend);
		pcur ++;
		pend ++;
	}
}
