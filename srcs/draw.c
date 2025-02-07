/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/02/07 12:39:47 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <math.h>
#include "utils.h"
#define PI 3.14159265359
#define	ISO_ANGLE 0.5

void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;
	if (x >= 1920 || y >= 1080 || x <= 0 || y <= 0 )
		return;
	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	join_point(t_data *data)
{
	int i;
	int j;
	t_point	point_a;
	t_point	point_b;
	
	i = 0;
	j = 0;
	while (i < data->map.memory_rows)
	{
		while (j < data->map.memory_cols - 1)
		{
			point_a.x = data->map.points[i][j].x;
			point_a.y = data->map.points[i][j].y;
			point_b.x = data->map.points[i][j + 1].x;
			point_b.y = data->map.points[i][j + 1].y;
			point_b.color = data->map.points[i][j + 1].color;
			choose_bresenham_algo(data, point_a, point_b);
			if (i < data->map.memory_rows - 1)
			{
				point_b.x = data->map.points[i + 1][j].x;
				point_b.y = data->map.points[i + 1][j].y;
				point_a.color = data->map.points[i][j].color;
				choose_bresenham_algo(data, point_b, point_a);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void isometrics_cordonate(t_data *win)
{
	int i;
	int j;
	int original_x;
    int original_y;
	double a;
	a = 0.523599;

	i = 0;
	j = 0;
	while (i < win->map.memory_rows)
	{
		while (j < win->map.memory_cols)
		{
			original_x = win->map.points[i][j].x;
			original_y = win->map.points[i][j].y;
			win->map.points[i][j].x = original_x * cos(a) + original_y * cos(a + 2) + win->map.points[i][j].z * cos(a - 2);
			win->map.points[i][j].y = original_x * sin(a) + original_y * sin(a + 2) + win->map.points[i][j].z * sin(a - 2);
			win->map.points[i][j].x += 800;
			win->map.points[i][j].y += 200;
			put_pixel(win, win->map.points[i][j].x, win->map.points[i][j].y, 0xFFFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
	join_point(win);
}
