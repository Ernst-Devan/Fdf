/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/01/31 17:58:44 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"
void initial_program(t_data *win)
{
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
