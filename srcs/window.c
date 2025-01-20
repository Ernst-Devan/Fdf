/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/01/20 21:49:54 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void inital_window()
{
	void	*mlx;
	void	*mlx_win;
	t_data window;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Visualiser");
	window.img = mlx_new_image(mlx, 1920, 1080);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_lenght, &window.endian);
	
	mlx_put_image_to_window(mlx, mlx_win, window.img, 0, 0);
	mlx_loop(mlx);
}