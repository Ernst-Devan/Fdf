/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/01/23 13:33:05 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"
void initial_program(t_data *window)
{
	int rows;
	int cols;
	int i;
	t_map **map;
	
	rows = 0;
	cols = 0;
	i = 0;

	if (check_map(&rows, &cols) == 1)
	{
		ft_printf("Invalid map\n");
		exit(1);
	}
		
	map = malloc((rows) * sizeof(t_map *));
	while (i < rows)
		map[i++] = malloc((cols) * sizeof(t_map));
	get_map_value(map, &rows, &cols);	
	isometrics_cordonate(window, map, &rows, &cols);
}

void inital_window()
{
	void	*mlx;
	t_data window;
	void	*mlx_win;

	mlx = mlx_init();
	window.width = 1920;
	window.lenght = 1080;
	
	mlx_win = mlx_new_window(mlx, window.width, window.lenght, "test");
	window.img = mlx_new_image(mlx, window.width, window.lenght);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_lenght, &window.endian);
	initial_program(&window);
	mlx_put_image_to_window(mlx, mlx_win, window.img, 0, 0);
	mlx_loop(mlx);
}