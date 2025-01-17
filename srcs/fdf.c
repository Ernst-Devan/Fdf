/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:45:05 by dernst            #+#    #+#             */
/*   Updated: 2025/01/17 22:58:22 by dernst           ###   ########lyon.fr   */
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

void	bresenham_algorithm(t_data *data, int Ax, int Ay, int Bx, int By)
{
	int x;
	int y;
	int P;
	int step;
	
	if (By >= Ay)
		step = 1;
	else
		step = -1;	
	x = Ax;
	y = Ay;
	P = 2*(abs(By - Ay) - abs(Bx - Ax));
	while (x <= Bx)
	{
		put_pixel(data, x, y, 0xFFFFFFFF);
		x++;
		if (P < 0)
			P = P + 2 * (abs(By - Ay));
		else
		{
			P = P + 2 * (abs(By - Ay)) - 2 *(abs(Bx - Ax));
			y += step;
		}
	}
}

void	join_point(t_data *data, t_pair **Pair)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 14)
	{
		while (j < 15)
		{
			bresenham_algorithm(data, Pair[i][j].x, Pair[i][j].y, Pair[i][j + 1].x, Pair[i][j+1].y);
			bresenham_algorithm(data, Pair[i + 1][j].x, Pair[i + 1][j].y, Pair[i][j].x, Pair[i][j].y);
			j++;	
		}
		j = 0;
		i++;
	}
	while (j < 15)
	{
		bresenham_algorithm(data, Pair[i][j].x, Pair[i][j].y, Pair[i][j + 1].x, Pair[i][j+1].y);
		j++;
	}
}

void	create_grid(t_data *data, int x, int y, t_pair **map)
{
	int cols;
	int rows;
	int x_temp;
	int y_temp;
	int i;
	int j;
	
	cols = 15;
	rows = 15;	
	//bresenham_algorithm(data,x - 520, y + 300, x,y);
	//bresenham_algorithm(data, x, y + 600, x + 520 , y + 300);

	//Horizontal
	// x : 520 / 10 | y = 300 / 10

	//Vertical
	// x : 520 / 10 | y = 300 / 10 
	x_temp = x;
	y_temp = y;
	
	i = 0;
	j = 0;
	while (i < rows)
	{
		while (j < cols)
		{
			put_pixel(data, x_temp, y_temp, 0xFFFFFFFF);
			//bresenham_algorithm(data, x_temp, y_temp, x_temp + 52, y_temp + 30);
			map[i][j].x = x_temp;
			map[i][j].y = y_temp;
			ft_printf("%d ; %d \n", map[i][j].x, map[i][j].y);
			x_temp += (520 / cols);
			y_temp += (300 / rows);
			j++;
		}
		j = 0;
		//map[m]->x = x_temp;
		//map[m]->y = y_temp;
		x -= 520 / cols;
		x_temp = x;
		y += 300 / rows;
		y_temp = y;
		i++;
	}


	join_point(data, map);

	//bresenham_algorithm(data, x,y, x + 520, y + 300);

	//bresenham_algorithm(data, x - 520, y + 300, x , y + 600);

	

}

// MAYBE NEED TO MAKE A STRUCT OF THE LINE_POINT TO HAVE ACCESS TO HIS LENGHT CAUSE ELSE WE CAN'T STOP THE READ INSIDE IT  


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
	rows = 45;
	cols = 45;

	t_pair **map;
	map = malloc(rows * sizeof(t_pair *));
	if (!map)
		return (1);
	
	while (i < rows)
	{
		map[i] = malloc(cols * sizeof(t_pair));
		if (!map[i])
			return(1);
			//Clean all the the map
		i++;
	}
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	create_grid(&img, 960, 100, map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
	mlx_loop(mlx);
}