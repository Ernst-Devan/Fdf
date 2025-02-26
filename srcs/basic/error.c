/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:54 by dernst            #+#    #+#             */
/*   Updated: 2025/02/26 14:12:16 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

void	cleanup(t_map *maps)
{
	size_t	i;

	i = 0;
	while (i < maps->rows)
	{
		free(maps->points[i]);
		maps->points[i] = NULL;
		i++;
	}
	free(maps->points);
	maps->points = NULL;
}

void	exiting(t_data *win, char *line)
{
	if (win)
	{
		if (win->img)
			mlx_destroy_image(win->mlx, win->img);
		if (win->win_ptr)
			mlx_destroy_window(win->mlx, win->win_ptr);
		if (win->mlx)
		{
			mlx_destroy_display(win->mlx);
			free(win->mlx);
		}
		if (win->basic.points)
			cleanup(&win->basic);
		if (win->modified.points)
			cleanup(&win->modified);
	}
	if (line)
		free(line);
	exit(1);
}
