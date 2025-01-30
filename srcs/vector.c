/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:16:02 by dernst            #+#    #+#             */
/*   Updated: 2025/01/31 00:10:34 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

void	map_first_alloc(t_data *win)
{
	t_point **points;

	points = malloc(1 * sizeof(t_point*));
	if (!points)
		exit(1);
	points[0] = malloc(win->map.memory_cols * sizeof(t_point));
	if (!points[0])
		exit(1);
	win->map.points = points;
}

void	cleanup(t_data *win, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(win->map.points[i]);
		i++;
	}
	free(win->map.points);
	win->map.points = NULL;
}

void	memlistcpy(t_point *rows, t_point *new_rows, size_t n)
{
	size_t	i;
	i = 0;
	while (i < n)
	{
		
		new_rows[i].x = rows[i].x;
		new_rows[i].y = rows[i].y;
		new_rows[i].z = rows[i].z;
		new_rows[i].color = rows[i].color;
		i++;
	}
}


//TODOz Failed allocation and reset the win->cols must be equals 0 and not 1
int	map_reaalloc(t_data *win)
{
	t_point	**new_points;
	size_t	i;
	
	win->map.memory_rows++;
	new_points = malloc(win->map.memory_rows + 1 * sizeof(t_point*));
	if (!new_points)
		exit(1);
	i = 0;
	while (i < win->map.memory_rows + 1)
	{
		new_points[i] = malloc(win->map.memory_cols + 1 * sizeof(t_point));
		if (!new_points[i])
			cleanup(win, i);
		if (i < win->map.memory_rows)
			memlistcpy(win->map.points[i], new_points[i], win->map.memory_cols + 1);
		i++;
	}
	free(win->map.points);
	win->map.points = new_points;
	win->map.rows++;
	win->map.cols = 0;
	return(0);
}


void	map_add_point(t_data *win, t_point point)
{
	if (win->map.cols >= win->map.memory_cols)
		map_reaalloc(win);
	win->map.points[win->map.rows][win->map.cols].x = point.x;
	win->map.points[win->map.rows][win->map.cols].y = point.y;
	win->map.points[win->map.rows][win->map.cols].z = point.z;
	win->map.points[win->map.rows][win->map.cols].color = point.color;
	win->map.cols++;
}