#ifndef MAIN_HH
# define MAIN_HH

# include "common.h"

extern t_dlist	g_list;

int				print_node(t_dlist_iter *it);
int				test_add();
int				test_remfirst();
int				test_clear();

#endif
