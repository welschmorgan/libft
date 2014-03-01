/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 04:56:20 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 05:38:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H

# include <libft_string.h>
# include <libft_dlist.h>
# include "units"

# define UNIT_NAME_LENGTH		50

typedef int						(*t_unit_test_func)(int, char **);

typedef struct					s_unit_test
{
	char						name[UNIT_NAME_LENGTH];
	t_unit_test_func			func;
}								t_unit_test;

typedef struct					s_units
{
	t_uint						progress;
	t_uint						total;
	int							last_error;
	t_dlist						tests;
}								t_units;

extern t_units					g_units;

t_units							*units_init(t_units *u);
void							units_add(char const *name,
										  t_unit_test_func func);

#endif /* !MAIN_H */
