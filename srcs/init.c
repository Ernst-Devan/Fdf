/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:08 by dernst            #+#    #+#             */
/*   Updated: 2025/02/09 17:23:53 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	init_map()
{
	t_map	map;
	
	map.cols = 0;
	map.rows = 0;
	map.memory_cols = 0;
	map.memory_rows = 1;
	map.points = NULL;
	return (map);
}

void init_data(t_data *win)
{
	win->img = NULL;
	win->addr = NULL;
	win->mlx = NULL;
	win->win_ptr = NULL;
	win->bits_per_pixel = 0;
	win->line_lenght = 0;
	win->endian = 0;
	win->fd_map = "maps/42.fdf";
	win->factor_scale = 40;
	win->factor_z = 1;
	win->move_x = 800;
	win->move_y = 200;
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