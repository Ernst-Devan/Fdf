/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/02/10 23:18:54 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <math.h>
#include "utils.h"

void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;
	if (x >= W_WIDTH || y >= W_HEIGHT || x <= 0 || y <= 0 )
		return;
	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	adding_factor(t_data *win, t_point *point)
{	
	point->x += win->move_x;
	point->y += win->move_y;
}

//! All point looks don't be joint between us
void	join_point(t_data *win)
{
	int i;
	int j;
	t_point	point_a;
	t_point	point_b;
	
	i = 0;
	j = 0;
	while (i < win->basic.memory_rows)
	{
		while (j < win->basic.memory_cols - 1)
		{
			init_point(&point_a);
			init_point(&point_b);
			point_a.x = win->modified.points[i][j].x;
			point_a.y = win->modified.points[i][j].y;
			point_b.x = win->modified.points[i][j + 1].x;
			point_b.y = win->modified.points[i][j + 1].y;
			point_b.color = win->modified.points[i][j + 1].color;
			point_a.color = win->modified.points[i][j].color;
			choose_bresenham_algo(win, point_a, point_b);
			if (i < win->basic.memory_rows - 1)
			{
				point_b.x = win->modified.points[i + 1][j].x;
				point_b.y = win->modified.points[i + 1][j].y;
				choose_bresenham_algo(win, point_b, point_a);
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < win->basic.memory_rows - 1)
	{
		point_a.x = win->modified.points[i][win->basic.memory_cols - 1].x;
		point_a.y = win->modified.points[i][win->basic.memory_cols - 1].y;
		point_a.color = win->modified.points[i][win->basic.memory_cols - 1].color;
		point_b.x = win->modified.points[i + 1][win->basic.memory_cols - 1].x;
		point_b.y = win->modified.points[i + 1][win->basic.memory_cols - 1].y;
		choose_bresenham_algo(win, point_b, point_a);
		i++;
	}
}

void isometrics_projection(t_data *win)
{
	int i;
	int j;
	t_point	temp;

	i = 0;
	j = 0;
	while (i < win->basic.memory_rows)
	{
		while (j < win->basic.memory_cols)
		{
			temp.x = win->basic.points[i][j].x * win->factor_scale;
			temp.y = win->basic.points[i][j].y * win->factor_scale;
			temp.z = win->basic.points[i][j].z * win->factor_scale * win->factor_z;
			win->modified.points[i][j].x = temp.x * cos(ISO) + temp.y * cos(ISO + 2) + temp.z * cos(ISO - 2);
			win->modified.points[i][j].y = temp.x * sin(ISO) + temp.y * sin(ISO + 2) + temp.z * sin(ISO - 2);
			adding_factor(win, &win->modified.points[i][j]);
			put_pixel(win, win->modified.points[i][j].x, win->modified.points[i][j].y, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}


void	apply_projection(t_data *win)
{
	isometrics_projection(win);
	join_point(win);
}
