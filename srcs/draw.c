/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/01/22 18:02:09 by dernst           ###   ########lyon.fr   */
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

void	join_point(t_data *data, t_map **map, int cols, int rows)
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
				bresenham_algorithm(data, map[i + 1][j - 1].x, map[i + 1][j - 1].y, map[i][j].x, map[i][j].y);
			bresenham_algorithm(data, map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j+1].y);
			bresenham_algorithm(data, map[i + 1][j].x, map[i + 1][j].y, map[i][j].x, map[i][j].y);

			j++;	
		}
		j = 0;
		i++;
	}
}

void isometrics_cordonate(t_data *window, t_map **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		while (j < 19)
		{
			map[i][j].x = ((sqrt(2) / 2) * (map[i][j].x - map[i][j].y));
			map[i][j].y = (sqrt(2.0 / 3.0) * map[i][j].z) - ((1.0 / sqrt(6.0)) * (map[i][j].x + map[i][j].y));
			map[i][j].x += 960;
			map[i][j].y += 540;
			put_pixel(window, map[i][j].x, map[i][j].y, 0xFFFFFFFF);
			
			j++;
		}
		j = 0;
		i++;
	}

	join_point(window, map, 16, 10);
}
