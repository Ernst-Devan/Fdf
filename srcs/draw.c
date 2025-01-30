/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/01/30 23:33:55 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <math.h>
#include "utils.h"
#define PI 3.14159265359



void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//// MAKE BRESENHAM ALGO FOR ALL LINE POSSINLE
////JUST NEED TO REVERSE AU LIEU DE FAIRE AX TO BX SI SA MARCHE APS ON FAIT BX TO AX ET LA POUF SA MARCHE
//void	bresenham_algorithm(t_data *data, int Ax, int Ay, int Bx, int By)
//{
//	int x;
//	int y;
//	int P;
//	int step;
	
//	if (By >= Ay)
//		step = 1;
//	else
//		step = -1;	
//	x = Ax;
//	y = Ay;
//	P = 2*(abs_value(By - Ay) - abs(Bx - Ax));
//	while (x <= Bx)
//	{
//		put_pixel(data, x, y, 0xFFFFFFFF);
//		x++;
//		if (P < 0)
//			P = P + 2 * (abs_value(By - Ay));
//		else
//		{
//			P = P + 2 * (abs_value(By - Ay)) - 2 *(abs_value(Bx - Ax));
//			y += step;
//		}
//	}
//}

//void	join_point(t_data *data, t_map **map, int rows, int cols)
//{
//	int i;
//	int j;

//	ft_printf("%d, %d \n", rows, cols);
//	i = 0;
//	j = 0;
//	while (i < rows)
//	{
//		while (j < cols)
//		{
//			ft_printf("i:%d j:%d \n",  i,j);
//			bresenham_algorithm(data, map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j+1].y);
//			if (i < rows - 1)
//				bresenham_algorithm(data, map[i + 1][j].x, map[i + 1][j].y, map[i][j].x, map[i][j].y);
//			j++;	
//		}
//		j = 0;
//		i++;
//	}
//}


void isometrics_cordonate(t_data *win)
{
	int i;
	int j;
	double a;
	a = 0.5;

	i = 0;
	j = 0;
	while (i < win->map.memory_rows)
	{
		while (j < win->map.memory_cols)
		{
			win->map.points[i][j].x = win->map.points[i][j].x * cos(a) + win->map.points[i][j].y * cos(a + 2) + win->map.points[i][j].z * cos(a - 2);
			win->map.points[i][j].y = win->map.points[i][j].x * sin(a) + win->map.points[i][j].y * sin(a + 2) + win->map.points[i][j].z * sin(a - 2);
			win->map.points[i][j].x += 800;
			win->map.points[i][j].y += 350;
			//put_pixel(win, win->map.points[i][j].x, win->map.points[i][j].y, 0xFFFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}

	//join_point(window, map, *rows, *cols);
}
