/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:16:02 by dernst            #+#    #+#             */
/*   Updated: 2025/02/17 11:36:38 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

int	map_first_alloc(t_map *map)
{
	t_point	**points;

	points = malloc(1 * sizeof(t_point *));
	if (!points)
		return (1);
	points[0] = malloc(map->memory_cols * sizeof(t_point));
	if (!points[0])
		return (1);
	map->points = points;
	return (0);
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

int	map_reaalloc(t_map *map)
{
	t_point	**new_points;
	size_t	i;

	map->memory_rows++;
	new_points = malloc(map->memory_rows * sizeof(t_point *));
	if (!new_points)
		return (1);
	i = 0;
	while (i < map->memory_rows)
	{
		new_points[i] = malloc(map->memory_cols * sizeof(t_point));
		if (!new_points[i])
			return (1);
		if (i < map->memory_rows - 1)
			memlistcpy(map->points[i], new_points[i], map->memory_cols);
		i++;
	}
	cleanup(map);
	map->points = new_points;
	map->cols = 0;
	return (0);
}

int	map_add_point(t_map *map, t_point point)
{
	if (map->cols >= map->memory_cols)
		if (map_reaalloc(map))
			return (1);
	map->points[map->rows][map->cols].x = point.x;
	map->points[map->rows][map->cols].y = point.y;
	map->points[map->rows][map->cols].z = point.z;
	map->points[map->rows][map->cols].color = point.color;
	map->cols++;
	if (map->cols > map->memory_cols - 1)
		map->rows++;
	return (0);
}
