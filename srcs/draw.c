/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:47:07 by dernst            #+#    #+#             */
/*   Updated: 2025/02/04 16:04:50 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <math.h>
#include "utils.h"
#define PI 3.14159265359
#define	ISO_ANGLE 0.5



void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//! MAKE BRESENHAM ALGO FOR ALL LINE POSSINLE
//!JUST NEED TO REVERSE AU LIEU DE FAIRE AX TO BX SI SA MARCHE APS ON FAIT BX TO AX ET LA POUF SA MARCHE
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

void	bresenham_slope_bigger(t_data *data, int Ax, int Ay, int Bx, int By)
{
	int	x;
	int y;
	int P;
	int step;
	
	if (By >= Ay)
		step = 1;
	else
		step = -1;	
	x = Ax;
	y = Ay;
	P = 2*(abs_value(Bx - Ax) - abs(By - Ay));
	while (y <= By)
	{
		put_pixel(data, x, y, 0xFFFFFFFF);
		y++;
		if (P < 0)
			P = P + 2 * (abs_value(Bx - Ax));
		else
		{
			P = P + 2 * (abs_value(Bx - Ax)) - 2 *(abs_value(By - Ay));
			x += step;
		}
	}
}
//void	choose_bresenham_algo(t_data *data, int Ax, int Ay, int Bx, int By)
//{
//	if ()
//		bresenham_slope_bigger(data, Ax, Ay Bx, By);
//	else
//		bresenham_slope_smaller(data, Ax, Ay, Bx, By);
		
//}

void	join_point(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->map.memory_rows)
	{
		while (j < data->map.memory_cols)
		{
			bresenham_algorithm(data, data->map.points[i][j].x, data->map.points[i][j].y, data->map.points[i][j + 1].x, data->map.points[i][j+1].y);
			if (i < data->map.memory_rows - 1)
				bresenham_algorithm(data, data->map.points[i + 1][j].x, data->map.points[i + 1][j].y, data->map.points[i][j].x, data->map.points[i][j].y);
			j++;
		}
		j = 0;
		i++;
	}
}



void isometrics_cordonate(t_data *win)
{
	int i;
	int j;
	int original_x;
    int original_y;
	double angle;
	angle = 0.523599;
	int	x;
	int	y;

	i = 0;
	j = 0;
	while (i < win->map.memory_rows)
	{
		while (j < win->map.memory_cols)
		{
			original_x = win->map.points[i][j].x;
			original_y = win->map.points[i][j].y;
			win->map.points[i][j].x = (original_x - original_y) * cos(angle);
            win->map.points[i][j].y = (original_x + original_y) * sin(angle) - win->map.points[i][j].z;
			win->map.points[i][j].x += 800;
			win->map.points[i][j].y += 200;
			put_pixel(win, win->map.points[i][j].x, win->map.points[i][j].y, 0xFFFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
	join_point(win);
}
