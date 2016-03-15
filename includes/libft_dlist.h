/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_dlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:17:28 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 12:38:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DLIST_H
# define LIBFT_DLIST_H

# include <string.h>
# include "libft_types.h"

# define _DEBUG_DLIST	0

/*
** Represents a policy to apply on each node
**	NF_NONE: no flags at all
**	NF_DESTROY_NODE: destroys node in remove functions
**	NF_DESTROY_DATA: destroys user data in remove functions
**	NF_DESTROY_ALL: destroys node & user data in remove functions
**	NF_STATE_HIDDEN: sets the node in hidden state
**	NF_STATE_STANDOUT: sets the node in standout mode
**	NF_STATE_SELECTED: sets the node selected
*/
typedef enum		e_dnode_flag
{
	NF_NONE = 0,
	NF_DESTROY_NODE = 1 << 1,
	NF_DESTROY_DATA = 1 << 2,
	NF_DESTROY_ALL = NF_DESTROY_NODE | NF_DESTROY_DATA
}					t_dnode_flag;

/*
** Represents a link inside the list
*/
typedef struct		s_dnode
{
	struct s_dlist	*parent;
	void			*data;
	struct s_dnode	*next;
	struct s_dnode	*prev;
	unsigned int	flag;
	size_t			size;
}					t_dnode;

typedef void		(*t_dnode_deleter)(t_dnode *);

void				ft_dlist_deleter(t_dnode *node);
/*
** Represents a linked list of t_dnodes
** Tail: the starting node of this list
** Head: the last node of this list
** Size: Optionnal, increments or decrements
** when you add or remove t_dnodes
*/
typedef struct		s_dlist
{
	size_t			size;
	t_dnode			*tail;
	t_dnode			*head;
}					t_dlist;

typedef struct		s_dlist_iter
{
	t_dlist			*list;
	t_dnode			*node;
	size_t			id;
}					t_dlist_iter;

void				ft_dlist_destroy(t_dlist **list, t_dnode_deleter deleter);
t_dlist				*ft_dlist_dup(const t_dlist *source);
t_dlist				*ft_dlist_copy(t_dlist *dest,
								const t_dlist *source);
t_dlist				*ft_dlist_init(t_dlist *list);
t_dlist				*ft_dlist_new();
void				ft_dlist_remove(t_dlist *list,
								t_dnode **node,
								t_dnode_deleter deleter);

t_bool				ft_dlist_empty(t_dlist *list);
size_t				ft_dlist_size(t_dlist *list, int recompute);
t_dlist_iter		ft_dlist_begin(t_dlist *list);
t_dlist_iter		ft_dlist_end(t_dlist *list);

/*
** Adds a node to the list
*/
t_dnode				*ft_dlist_add_back(t_dlist *list,
										t_dnode *new_node);
t_dnode				*ft_dlist_add_front(t_dlist *list,
										t_dnode *new_node);
t_dnode				*ft_dlist_push_back(t_dlist *list,
										t_dnode *new_node);
t_dnode				*ft_dlist_push_front(t_dlist *list,
										t_dnode *new_node);
/*
** Creates a node from a string and adds it the the list
*/
t_dnode				*ft_dlist_add_back_str(t_dlist *lst,
										char const *str,
										unsigned int flags);
t_dnode				*ft_dlist_add_front_str(t_dlist *lst,
											char const *str,
											unsigned int flags);
t_dnode				*ft_dlist_add_back_strn(t_dlist *lst,
											char const *str,
											size_t const n,
											unsigned int flags);
t_dnode				*ft_dlist_add_front_strn(t_dlist *lst,
											char const *str,
											size_t const n,
											unsigned int flags);
t_dnode				*ft_dlist_push_back_str(t_dlist *lst,
											char const *str,
											unsigned int flags);
t_dnode				*ft_dlist_push_front_str(t_dlist *lst,
											char const *str,
											unsigned int flags);

void				ft_dlist_clear(t_dlist *list,
									t_dnode_deleter deleter);

int					ft_dlist_contains(t_dlist *list,
									t_dnode *node);

t_dnode				*ft_dlist_extract(t_dlist *list,
									t_dnode *node);
t_dnode				*ft_dnode_init(t_dnode *n,
								void *data,
								size_t size,
								int flags);
t_dnode				*ft_dnode_new(void *data,
								size_t size,
								unsigned int flags);

t_dnode				*ft_dnode_new_str(char const *str,
									unsigned int flags);
t_dnode				*ft_dnode_new_strn(char const *str,
									size_t const n,
									unsigned int flags);
char				*ft_dnode_flag_str(t_dnode *node);
char				*ft_dnode_flag_name(t_dnode_flag flag);

t_dnode				*ft_dlist_insert_before(t_dlist *list,
											t_dnode *new_node,
											t_dnode *next);
t_dnode				*ft_dlist_insert_after(t_dlist *list,
										t_dnode *new_node,
										t_dnode *prev);
t_dnode				*ft_dlist_insert_first(t_dlist *list,
										t_dnode *node);

/*
** iterator stuff
*/
t_dnode				*ft_dlist_iter_prev(t_dlist_iter *i);
t_dnode				*ft_dlist_iter_next(t_dlist_iter *i);

int					ft_dlist_iter_valid(t_dlist_iter *i);

t_dlist_iter		*ft_dlist_iter_begin(t_dlist_iter *i);
t_dlist_iter		*ft_dlist_iter_end(t_dlist_iter *i);

void				*ft_dlist_iter_data(t_dlist_iter *i);

t_dlist_iter		*ft_dlist_iter_reset(t_dlist_iter *i);
t_dlist_iter		*ft_dlist_iter_init(t_dlist_iter *i, t_dlist *l);

typedef int			(*t_dlist_iter_fn)(t_dlist_iter *);

int					ft_dlist_iterate(t_dlist *l, t_dlist_iter_fn fn);
int					ft_dlist_riterate(t_dlist *l, t_dlist_iter_fn fn);

#endif
