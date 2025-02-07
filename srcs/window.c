/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/02/05 22:34:14 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "limits.h"
#include "errno.h"
#include "libft.h"
#include <X11/keysym.h>

void initial_program(t_data *win)
{
	//! Error with straight line choose_bresenham_algo(win, 150, 150, 150, 200);
	//! Protect all mlx function if they failed
	//choose_bresenham_algo(win, 150, 150, 155, 190);
	parsing_nb_line(win);
	parsing_map(win);
	isometrics_cordonate(win);
}



int	handle_input(int key, t_data *win)
{
	if (key == XK_Escape)
		mlx_destroy_window(win->mlx, win->win_ptr);
	if (key == XK_d || key == XK_a || key == XK_s || key == XK_w || key == XK_o || key == XK_l)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, 1920, 1080);
		if (key == XK_d)
			move(win, 10, 0);
		if (key == XK_a)
			move(win, -10, 0);
		if (key == XK_w)
			move(win, 0, -10);
		if (key == XK_s)
			move(win, 0, 10);
		if (key == XK_o)
			zoom(win, 2);
		if (key == XK_l)
			zoom(win, -2);
		mlx_put_image_to_window(win->mlx, win->win_ptr, win->img, 0, 0);
	}
	return (0);
}


void inital_window(char *map_name)
{
	t_data	win;

	init_data(&win);
	win.mlx = mlx_init();
	if (!win.mlx)
		return;
	if (map_name)
		win.fd_map = map_name;
	win.win_ptr = mlx_new_window(win.mlx, 1920, 1080, "Fdf");
	win.img = mlx_new_image(win.mlx, 1920, 1080);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_lenght, &win.endian);
	initial_program(&win);
	mlx_put_image_to_window(win.mlx, win.win_ptr, win.img, 0, 0);
	mlx_key_hook(win.win_ptr, handle_input, &win);
	mlx_loop(win.mlx);
}
