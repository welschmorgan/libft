/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 04:13:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 05:58:57 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft_string.h>
#include <stdlib.h>
#include "units.h"
#include "main.h"

t_units							*units_init(t_units *u)
{
	if (u)
	{
		u->progress = 0;
		u->total = 0;
		u->last_error = 0;
	}
	return (u);
}

void							units_add(t_units *u,
										  char const *name,
										  t_unit_test_func func)
{
	t_unit_test
	if (u)
	{
		
		ft_dlist_push_back(&u->tests,);
	}
}

int								main(int ac, char **av)
{
	t_units	u;

	units_init(&u);
	units_add("printf", main_printf(ac, av));
	return (EXIT_SUCCESS);
}
