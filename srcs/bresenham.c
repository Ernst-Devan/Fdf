/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:48 by dernst            #+#    #+#             */
/*   Updated: 2025/02/05 17:47:51 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

void	bresenham_smaller(t_data *data, int Ax, int Ay, int Bx, int By)
{
	int	x;
	int	y;
	int	P;
	int	step;
	
	if (By >= Ay)
		step = 1;
	else
		step = -1;
	x = Ax;
	y = Ay;
	P = 2*(abs_value(By - Ay) - abs_value(Bx - Ax));
	while (x <= Bx)
	{
		put_pixel(data, x, y, 0xFFFFFF);
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

void	bresenham_bigger_down(t_data *data, int Ax, int Ay, int Bx, int By)
{
	int	x;
	int	y;
	int	P;

	x = Ax;
	y = Ay;
	P = 2*(abs_value(Bx - Ax) - abs_value(By - Ay));
	while (y <= By)
	{
		put_pixel(data, x, y, 0xFFFFFFFF);
		y++;
		if (P < 0)
			P = P + 2 * (abs_value(Bx - Ax));
		else
		{
			P = P + 2 * (abs_value(Bx - Ax)) - 2 *(abs_value(By - Ay));
			x++;
		}
	}
}

void	bresenham_bigger_up(t_data *data, int Ax, int Ay, int Bx, int By)
{
	int	x;
	int	y;
	int	P;

	x = Ax;
	y = Ay;
	P = 2*(abs_value(Bx - Ax) - abs_value(By - Ay));
	while (y >= By)
	{
		put_pixel(data, x, y, 0xFFFFFFFF);
		y--;
		if (P < 0)
			P = P + 2 * (abs_value(Bx - Ax));
		else
		{
			P = P + 2 * (abs_value(Bx - Ax)) - 2 *(abs_value(By - Ay));
			x++;
		}
	}
}
void	choose_bresenham_algo(t_data *data, int Ax, int Ay, int Bx, int By)
{
	int	slope;

	if (By - Ay == 0 || (Bx - Ax) == 0)
		slope = 0;
	else
		slope = (By - Ay)/ (Bx - Ax);
	if (slope >= 1 || slope <= -1)
	{
		if (Ax >= Bx)
			if (slope <= -1)
				bresenham_bigger_down(data, Bx, By, Ax, Ay);
			else
				bresenham_bigger_up(data, Bx, By, Ax, Ay);
		else
			if (slope >= 1)
				bresenham_bigger_down(data, Ax, Ay, Bx, By);
			else
				bresenham_bigger_up(data, Ax, Ay, Bx, By);
	}
	else if (slope >= -1 && slope <= 1)
	{
		if (Ax >= Bx)
			bresenham_smaller(data, Bx, By, Ax, Ay);
		else
			bresenham_smaller(data, Ax, Ay, Bx, By);
	}
}
