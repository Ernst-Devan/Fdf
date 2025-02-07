/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:53:41 by dernst            #+#    #+#             */
/*   Updated: 2025/02/05 22:30:09 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	move(t_data *win, int x, int y)
{
	int i;
	int j;
	double a;
	a = 0.523599;

	i = 0;
	j = 0;
	while (i < win->map.memory_rows)
	{
		while (j < win->map.memory_cols)
		{
			win->map.points[i][j].x += x;
			win->map.points[i][j].y += y;
			put_pixel(win, win->map.points[i][j].x, win->map.points[i][j].y, 0xFFFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
	join_point(win);
	return (0);
}

int zoom(t_data *win, double zoom)
{
	int i;
	int j;
	double a;
	a = 0.523599;

	i = 0;
	j = 0;
	while (i < win->map.memory_rows)
	{
		while (j < win->map.memory_cols)
		{
			win->map.points[i][j].x *= zoom;
			win->map.points[i][j].y *= zoom;
			put_pixel(win, win->map.points[i][j].x, win->map.points[i][j].y, 0xFFFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
	join_point(win);
	return (0);
}