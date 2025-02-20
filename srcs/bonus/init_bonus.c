/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:08 by dernst            #+#    #+#             */
/*   Updated: 2025/02/20 17:18:51 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

t_map	init_map(void)
{
	t_map	map;

	map.cols = 0;
	map.rows = 0;
	map.memory_cols = 0;
	map.memory_rows = 1;
	map.points = NULL;
	return (map);
}

void	init_data(t_data *win)
{
	win->img = NULL;
	win->addr = NULL;
	win->mlx = NULL;
	win->win_ptr = NULL;
	win->bits_per_pixel = 0;
	win->line_lenght = 0;
	win->endian = 0;
	win->fd_map = "maps/42.fdf";
	win->f_scale = 0;
	win->factor_z = 0.1;
	win->r_z = 0;
	win->r_x = 0;
	win->r_y = 0;
	win->m_x = 0;
	win->m_y = 0;
	win->basic = init_map();
	win->modified = init_map();
}

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0xFFFFFF;
}
