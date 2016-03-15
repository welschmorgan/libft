/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 01:36:32 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/23 01:37:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}