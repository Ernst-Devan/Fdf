/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/02/04 16:04:53 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "limits.h"
#include "errno.h"
#include "libft.h"

void initial_program(t_data *win)
{
	//bresenham_slope_bigger(win, 150,150,155,180);
	parsing_map(win);
	isometrics_cordonate(win);
}

void inital_window(char *map_name)
{
	void	*mlx;
	t_data	win;
	void	*mlx_win;

	mlx = mlx_init();
	init_data(&win);
	if (map_name)
		win.fd_map = map_name;
	win.width = 1920;
	win.lenght = 1080;
	mlx_win = mlx_new_window(mlx, win.width, win.lenght, "Fdf");
	win.img = mlx_new_image(mlx, win.width, win.lenght);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_lenght, &win.endian);
	initial_program(&win);
	mlx_put_image_to_window(mlx, mlx_win, win.img, 0, 0);
	mlx_loop(mlx);
}
