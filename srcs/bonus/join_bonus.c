/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:46:19 by dernst            #+#    #+#             */
/*   Updated: 2025/02/20 18:21:26 by dernst           ###   ########lyon.fr   */
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
		*a = win->modified.points[i][j];
		*b = win->modified.points[i][j + 1];
		choose_bresenham_algo(win, *b, *a);
		if (i < win->basic.memory_rows - 1)
		{
			*b = win->modified.points[i + 1][j];
			choose_bresenham_algo(win, *b, *a);
		}
		j++;
	}
}

void	join_last(t_data *win, size_t i, t_point *a, t_point *b)
{
	a = &win->modified.points[i][win->basic.memory_cols - 1];
	b = &win->modified.points[i + 1][win->basic.memory_cols - 1];
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
