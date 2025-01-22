/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/01/22 16:08:22 by dernst           ###   ########lyon.fr   */
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
	
	rows = 12;
	cols = 19;
	i = 0;

	map = malloc((500) * sizeof(t_map *));
	while (i < rows)
	{
		map[i] = malloc((500) * sizeof(t_map));
		i++;
	}
	
	if (parsing_map(map) == 1)
	{
		ft_printf("Invalid map\n");
		exit(1);
	}

	isometrics_cordonate(window, map);
}

void inital_window()
{
	void	*mlx;
	t_data window;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1980, 1080, "test");
	window.img = mlx_new_image(mlx, 1920, 1080);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_lenght, &window.endian);
	initial_program(&window);
	mlx_put_image_to_window(mlx, mlx_win, window.img, 0, 0);
	mlx_loop(mlx);
}