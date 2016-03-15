/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:21:02 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/13 20:22:10 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <libft.h>

char				*ft_row_cell(t_row *row, int const col)
{
	if (row && col < row->ncols)
		return (row->buffer[col]);
	return (NULL);
}

char				*ft_row_cell_name(t_row *row, int const col)
{
	if (row && col < row->ncols)
		return (row->names[col]);
	return (NULL);
}

size_t				ft_row_length(t_row *row)
{
	int		col;
	size_t	size;

	col = 0;
	size = 0;
	while (col < row->ncols)
	{
		size += row->sizes[col] + ft_strlen(row->sep);
		col++;
	}
	return (size);
}


t_row	*ft_row_init(t_row *row, int const ncols,
					 int const *sizes, char const **names)
{
	int	i;
	if (!row)
		return (row);
	row->sep = "|";
	row->ncols = ncols;
	row->buffer = ft_memalloc(ncols * sizeof(char*));
	row->sizes = ft_memalloc(ncols * sizeof(int));
	row->names = ft_memalloc(ncols * sizeof(char*));
	ft_memcpy(row->sizes, sizes, sizeof(int) * ncols);
	i = 0;
	while (i < ncols)
	{
		row->buffer[i] = ft_strnew(CELL_LENGTH_MAX);
		row->names[i] = ft_strnew(CELL_LENGTH_MAX);
		ft_strpad(row->buffer[i], sizes[i], ' ');
		ft_strncpy(row->names[i], names[i], CELL_LENGTH_MAX);
		ft_strpad(row->names[i], sizes[i], ' ');
		ft_strpad(row->buffer[i], sizes[i], ' ');
		ft_row_set(row, i, "");
		i++;
	}
	return (row);
}

t_row	*ft_row_clear(t_row *row)
{
	int	i;

	i = 0;
	while (i < row->ncols)
	{
		if (row->buffer && row->buffer[i])
			ft_row_set(row, i, "");
		i++;
	}
	return (row);
}

t_row	*ft_row_reset(t_row *row)
{
	if (!row)
		return (row);
	int				i;
	i = 0;
	while (i < row->ncols)
	{
		if (row->buffer[i])
			ft_strdel(&row->buffer[i]);
		if (row->names[i])
			ft_strdel(&row->names[i]);
		i++;
	}
	ft_memdel((void**)row->buffer);
	if (row->names)
		ft_memdel((void**)row->names);
	if (row->sizes)
		ft_memdel((void**)&row->sizes);
	row->ncols = 0;
	return (row);
}

t_row	*ft_row_setf(t_row *row, int const col, char const *fmt, ...)
{
	static char	buf[255];
	va_list		args;

	va_start(args, fmt);
	vsnprintf(buf, 255, fmt, args);
	va_end(args);
	ft_row_set(row, col, buf);
	return (row);
}

t_row	*ft_row_set(t_row *row, int const col, char const *val)
{
	if (!row)
		return (row);
	if (col >= row->ncols)
		return (NULL);
	ft_strncpy(row->buffer[col], val, row->sizes[col]);
	ft_strpad_r(row->buffer[col], row->sizes[col], ' ');
	return (row);
}

void	ft_row_print_header(t_row const *row, int const endl)
{
	int		i;

	i = 0;
	while (i < row->ncols)
	{
		ft_putstr(row->names[i]);
		ft_putstr(row->sep);
		i++;
	}
	if (endl)
		ft_putendl("");
}

void	ft_row_print(t_row const *row, int const endl)
{
	int	i;
	i = 0;
	while (i < row->ncols)
	{
		ft_putstr(row->buffer[i++]);
		ft_putstr(row->sep);
	}
	if (endl)
		ft_putendl("");
}
