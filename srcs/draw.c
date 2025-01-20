/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/01/20 21:40:17 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <math.h>
#define PI 3.14159265359

int abs_value(int x)
{
	if(x < 0)
	{
		return(x * -1);
	}
	return (x);
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
	P = 2*(abs_value(By - Ay) - abs(Bx - Ax));
	while (x <= Bx)
	{
		put_pixel(data, x, y, 0xFFFFFFFF);
		x++;
		if (P < 0)
			P = P + 2 * (abs_value(By - Ay));
		else
		{
			P = P + 2 * (abs_value(By - Ay)) - 2 *(abs_value(Bx - Ax));
			y += step;
		}
	}
}

void	join_point(t_data *data, t_pair **Pair, int cols, int rows)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < rows)
	{
		while (j < cols + 1)
		{
			if (i == 0)
				bresenham_algorithm(data, Pair[i + 1][j - 1].x, Pair[i + 1][j - 1].y, Pair[i][j].x, Pair[i][j].y);
			bresenham_algorithm(data, Pair[i][j].x, Pair[i][j].y, Pair[i][j + 1].x, Pair[i][j+1].y);
			bresenham_algorithm(data, Pair[i + 1][j].x, Pair[i + 1][j].y, Pair[i][j].x, Pair[i][j].y);

			j++;	
		}
		j = 0;
		i++;
	}
}

void	create_grid_square(t_data *data, int x, int y, t_pair **map)
{
	int cols;
	int rows;
	int x_temp;
	int y_temp;
	int j;
	int i;

	cols = 10;
	rows = 10;
	j = 1;
	i = 0;
	int x_start;
	int y_start;

	int separation_x;
	int separation_y;
	
	x_start = x / 2;
	y_start = ((1080 - y) / 6);
	x_temp = x_start;
	y_temp = y_start;

	separation_x = tan(60 * PI / 180) * (y / 2);
	separation_y = y / 2 ;
	while (i < rows + 1)
	{
		while (j < cols + 1)
		{
			ft_printf("%d : %d\n", i , j);
			put_pixel(data, x_temp, y_temp, 0xFFFFFFFF);
			map[i][j].x = x_temp;
			map[i][j].y = y_temp;
			x_temp += (separation_x / cols);
			y_temp += (separation_y / cols);
			j++;
		}
		j = 0;
		x_start -= separation_x / rows;
		x_temp = x_start;
		y_start += separation_y / rows;
		y_temp = y_start;
		i++;
	}
	join_point(data, map, cols, rows);
}
