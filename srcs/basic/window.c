/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/02/26 14:14:36 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <math.h>

void	initial_window(t_data *win, char *map_name)
{
	if (map_name)
		win->fd_map = map_name;
	parsing_map(win);
	win->f_scale = sqrt(W_WIDTH * W_HEIGHT
			/ (win->basic.cols * win->basic.memory_rows)) * 0.5;
	win->m_x = (W_WIDTH / 2) - (((win->basic.cols * 0.4) * win->f_scale) / 2);
	win->m_y = (W_HEIGHT / 2) - (((win->basic.rows * 1.5) * win->f_scale) / 2);
	win->mlx = mlx_init();
	if (!win->mlx)
		exiting(win, NULL);
	win->win_ptr = mlx_new_window(win->mlx, W_WIDTH, W_HEIGHT, "Fdf");
	if (!win->win_ptr)
		exiting(win, NULL);
	win->img = mlx_new_image(win->mlx, W_WIDTH, W_HEIGHT);
	if (!win->img)
		exiting(win, NULL);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,
			&win->line_lenght, &win->endian);
	if (!win->addr)
		exiting(win, NULL);
	apply_projection(win);
	mlx_put_image_to_window(win->mlx, win->win_ptr, win->img, 0, 0);
	manage_hook(win);
	mlx_loop(win->mlx);
}
