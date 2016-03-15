/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch </var/mail/mwelsch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:17:13 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/12 18:53:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"
#include "main.h"

int		cleanup()
{
	return (0);
}

int		init()
{
	add_test("math: pow", test_pow);
	add_test("math: log10", test_log10);
	return (0);
}
