/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:46:19 by dernst            #+#    #+#             */
/*   Updated: 2025/02/18 16:38:41 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	join_horizontal(t_data *win, size_t i, t_point *a, t_point *b)
{
	size_t	j;

	j = 0;
	while (j < win->modified.memory_cols - 1)
	{
		init_point(a);
		init_point(b);
		a->x = win->modified.points[i][j].x;
		a->y = win->modified.points[i][j].y;
		b->x = win->modified.points[i][j + 1].x;
		b->y = win->modified.points[i][j + 1].y;
		a->color = win->modified.points[i][j].color;
		b->color = win->modified.points[i][j + 1].color;
		choose_bresenham_algo(win, *b, *a);
		if (i < win->basic.memory_rows - 1)
		{
			b->x = win->modified.points[i + 1][j].x;
			b->y = win->modified.points[i + 1][j].y;
			choose_bresenham_algo(win, *b, *a);
		}
		j++;
	}
}

void	join_last(t_data *win, size_t i, t_point *a, t_point *b)
{
	a->x = win->modified.points[i][win->basic.memory_cols - 1].x;
	a->y = win->modified.points[i][win->basic.memory_cols - 1].y;
	a->color = win->modified.points[i][win->basic.memory_cols - 1].color;
	b->x = win->modified.points[i + 1][win->basic.memory_cols - 1].x;
	b->y = win->modified.points[i + 1][win->basic.memory_cols - 1].y;
	b->color = win->modified.points[i + 1][win->basic.memory_cols - 1].color;
	choose_bresenham_algo(win, *b, *a);
}

void	join_point(t_data *win)
{
	size_t	i;
	size_t	j;
	t_point	a;
	t_point	b;

	i = 0;
	j = 0;
	while (i < win->basic.memory_rows)
	{
		init_point(&a);
		init_point(&b);
		join_horizontal(win, i, &a, &b);
		i++;
	}
	i = 0;
	while (i < win->basic.memory_rows - 1)
	{
		join_last(win, i, &a, &b);
		i++;
	}
}
