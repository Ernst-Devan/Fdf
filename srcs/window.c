/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/02/05 17:56:53 by dernst           ###   ########lyon.fr   */
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

//int	handle_input(int key, t_data *win)
//{
//	if (key == XK_Escape)
//		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
//	return (0);
//}

//void	manage_hook(t_data *win)
//{
//	mlx_key_hook(win->mlx_ptr, &handle_input, win);
//}

void inital_window(char *map_name)
{
	t_data	win;

	win.mlx_ptr = mlx_init();
	init_data(&win);
	if (map_name)
		win.fd_map = map_name;
	win.win_ptr = mlx_new_window(win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf");
	win.img = mlx_new_image(win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_lenght, &win.endian);
	//initial_program(&win);
	//manage_hook(&win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img, 0, 0);
	mlx_loop(win.mlx_ptr);
	//mlx_destroy_display(win.mlx_ptr);
	//!NEED TO ALL FREE
}
