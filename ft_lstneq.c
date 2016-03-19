/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstneq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 07:36:34 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/09 13:37:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool			ft_lstneq(t_list *a,
						t_list *b,
						t_content_comparator comp,
						size_t n)
{
	while (a && b && n)
	{
		if (comp(a->content, b->content) == FALSE)
			return (FALSE);
		a = a->next;
		b = b->next;
		n--;
	}
	return (TRUE);
}
