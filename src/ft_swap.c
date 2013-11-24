/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:34:47 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/24 20:36:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int		tmp;

	if (!a || !b)
		return ;
	tmp = *b;
	*b = *a;
	*a = tmp;
}
void	ft_swap(char *a, char *b)
{
	char	tmp;

	if (!a || !b)
		return ;
	tmp = *b;
	*b = *a;
	*a = tmp;
}
