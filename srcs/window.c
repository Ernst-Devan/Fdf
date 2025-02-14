/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/02/14 16:32:58 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

//! Protect all mlx function if they failed	
void initial_program(t_data *win)
{
	parsing_map(win);
	apply_projection(win);
}

void initial_window(char *map_name)
{
	t_data	win;

	init_data(&win);
	win.mlx = mlx_init();
	if (!win.mlx)
		exiting(&win);
	if (map_name)
		win.fd_map = map_name;
	win.win_ptr = mlx_new_window(win.mlx, W_WIDTH, W_HEIGHT, "Fdf");
	if (!win.win_ptr)
		exiting(&win);
	win.img = mlx_new_image(win.mlx, W_WIDTH, W_HEIGHT);
	if (!win.img)
		exiting(&win);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_lenght, &win.endian);
	initial_program(&win);
	mlx_put_image_to_window(win.mlx, win.win_ptr, win.img, 0, 0);
	manage_hook(&win);
	mlx_loop(win.mlx);
}