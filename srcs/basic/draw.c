/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/02/20 18:23:59 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <math.h>
#include "utils.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= W_WIDTH || y >= W_HEIGHT || x <= 0 || y <= 0)
		return ;
	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	adding_factor(t_data *win, t_point *point, int i, int j)
{
	point->x = win->basic.points[i][j].x * win->f_scale;
	point->y = win->basic.points[i][j].y * win->f_scale;
	point->z = win->basic.points[i][j].z * win->f_scale * win->factor_z;
	rotate_x(win, point);
	rotate_y(win, point);
	rotate_z(win, point);
}

void	point_projection(t_data *win)
{
	size_t	i;
	size_t	j;
	t_point	temp;

	i = 0;
	j = 0;
	while (i < win->modified.memory_rows)
	{
		while (j < win->modified.memory_cols)
		{
			init_point(&temp);
			adding_factor(win, &temp, i, j);
			win->modified.points[i][j].x = temp.x * cos(ISO) + temp.y
				* cos(ISO + 2) + temp.z * cos(ISO - 2);
			win->modified.points[i][j].y = temp.x * sin(ISO) + temp.y
				* sin(ISO + 2) + temp.z * sin(ISO - 2);
			win->modified.points[i][j].x += win->m_x;
			win->modified.points[i][j].y += win->m_y;
			j++;
		}
		j = 0;
		i++;
	}
}

void	apply_projection(t_data *win)
{
	point_projection(win);
	join_point(win);
}
