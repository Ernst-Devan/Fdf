/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/02/19 17:35:20 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <X11/X.h>

int	handle_window(t_data *win)
{
	exiting(win);
	return (0);
}

void	manage_hook(t_data *win)
{
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, &handle_keypress, win);
	mlx_hook(win->win_ptr, DestroyNotify, NoEventMask, &handle_window, win);
	mlx_hook(win->win_ptr, ButtonPress, ButtonPressMask, &handle_mouse, win);
}

void	initial_window(char *map_name)
{
	t_data	win;

	init_data(&win);
	if (map_name)
		win.fd_map = map_name;
	parsing_map(&win);
	win.mlx = mlx_init();
	if (!win.mlx)
		exiting(&win);
	win.win_ptr = mlx_new_window(win.mlx, W_WIDTH, W_HEIGHT, "Fdf");
	if (!win.win_ptr)
		exiting(&win);
	win.img = mlx_new_image(win.mlx, W_WIDTH, W_HEIGHT);
	if (!win.img)
		exiting(&win);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel,
			&win.line_lenght, &win.endian);
	if (!win.addr)
		exiting(&win);
	apply_projection(&win);
	mlx_put_image_to_window(win.mlx, win.win_ptr, win.img, 0, 0);
	manage_hook(&win);
	mlx_loop(win.mlx);
}
