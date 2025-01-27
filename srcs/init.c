/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:08 by dernst            #+#    #+#             */
/*   Updated: 2025/01/27 18:00:39 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	init_map()
{
	t_map	map;
	
	map.ishexa = 0;
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
	win->bits_per_pixel = 0;
	win->line_lenght = 0;
	win->endian = 0;
	win->status = 0;
	win->width = 0;
	win->lenght = 0;
	win->map = init_map();
}

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0xFFFFFFFF;
}