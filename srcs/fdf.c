/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:45:05 by dernst            #+#    #+#             */
/*   Updated: 2025/01/20 21:42:31 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// [] DO IN PAPER ALL STEP NEED TO ACHIEVE TO FINISH THIS PROJECT

// [x] MAKE A GIT REPOSITORY
// [x] ADD LIBFT
// [x] UNDERSTAND HOW WORK MINLIBX
// [x] INSTALL MINLIBX INSIDE THE PROJECT
// [] DONT FORGET TO ADD FLAGS DURINT THE COMPILATION
// [x] MAKE A WINDOWS 
// [] MAKE THE GRID
// [] ALL RETURN POINTER MUST BE CHECKED IF THEY RETURN NULL
// [] PROTECT NEGATIVE NUMBER INSIDE A PUT PIXEL
// [] CLOSE THE WINDOW WHITH THE CROSS AND ECHAP
// [] TO JOIN POINT WE NEED TO MAKE A MAP OF EACH POINT PLACED WITH HIS LOCATION LIKE THIS
// [] CHECK IF WE CAN USE THE EXIT FUNCTION TO ESCAPE FROM EACH FUNCTION WITH FAILED MALLOC FOR EXEMPLE
// [] DO THE ERROR MANAGEMENT
// [x] REMOVE THE FUNCTION ABS AND REMAKE IT 


// (10,2), (12,3), (14,4)
// (9,1), (10, -2), (14,-4)
// etc ..

// Without negative number 
// So we know that we must joint the map[0][0] and map[0][1] | map[0][0] with map[1][0]



#include "libft.h"
#include "fdf.h"
#include <mlx.h>

void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx;
	t_data img;
	void	*mlx_win;

	// Malloc with the result of the parsing 
	int rows;
	int cols;
	int i;
	
	i = 0;
	rows = 40;
	cols = 40;

	t_pair **map;
	map = malloc(rows * sizeof(t_pair *));
	if (!map)
		return (1);
	
	while (i < rows)
	{
		map[i] = malloc(cols * sizeof(t_pair));
		if (!map[i])
		{
			cleanup(map, i);
			return (1);
		}
		i++;
	}
	map[0][0].x = cols;
	map[0][0].y = rows;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	img.status = 0;
	create_grid_square(&img, 1920, 980, map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
	mlx_loop(mlx);
}
