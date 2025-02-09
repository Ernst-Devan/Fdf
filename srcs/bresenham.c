/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:48 by dernst            #+#    #+#             */
/*   Updated: 2025/02/08 16:52:23 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

void	bresenham_smaller(t_data *data, t_point point_a, t_point point_b)
{
	int	x;
	int	y;
	int	P;
	int	step;
	
	if (point_b.y >= point_a.y)
		step = 1;
	else
		step = -1;
	x = point_a.x;
	y = point_a.y;
	P = 2*(abs_value(point_b.y - point_a.y) - abs_value(point_b.x - point_a.x));
	while (x <= point_b.x)
	{
		put_pixel(data, x, y, point_b.color);
		x++;
		if (P < 0)
			P = P + 2 * (abs_value(point_b.y - point_a.y));
		else
		{
			P = P + 2 * (abs_value(point_b.y - point_a.y)) - 2 *(abs_value(point_b.x - point_a.x));
			y += step;
		}
	}
}

void	bresenham_bigger_down(t_data *data, t_point point_a, t_point point_b)
{
	int	x;
	int	y;
	int	P;

	x = point_a.x;
	y = point_a.y;
	P = 2*(abs_value(point_b.x - point_a.x) - abs_value(point_b.y - point_a.y));
	while (y <= point_b.y)
	{
		put_pixel(data, x, y, point_b.color);
		y++;
		if (P < 0)
			P = P + 2 * (abs_value(point_b.x - point_a.x));
		else
		{
			P = P + 2 * (abs_value(point_b.x - point_a.x)) - 2 *(abs_value(point_b.y - point_a.y));
			x++;
		}
	}
}

void	bresenham_bigger_up(t_data *data, t_point point_a, t_point point_b)
{
	int	x;
	int	y;
	int	P;

	x = point_a.x;
	y = point_a.y;
	P = 2*(abs_value(point_b.x - point_a.x) - abs_value(point_b.y - point_a.y));
	while (y >= point_b.y)
	{
		put_pixel(data, x, y, point_b.color);
		y--;
		if (P < 0)
			P = P + 2 * (abs_value(point_b.x - point_a.x));
		else
		{
			P = P + 2 * (abs_value(point_b.x - point_a.x)) - 2 *(abs_value(point_b.y - point_a.y));
			x++;
		}
	}
}
void	choose_bresenham_algo(t_data *data, t_point point_a, t_point point_b)
{
	int	slope;

	if (point_b.y - point_a.y == 0 || (point_b.x - point_a.x) == 0)
		slope = 0;
	else
		slope = (point_b.y - point_a.y)/ (point_b.x - point_a.x);
	if (slope >= 1 || slope <= -1)
	{
		if (point_a.x >= point_b.x)
			if (slope <= -1)
				bresenham_bigger_down(data, point_b, point_a);
			else
				bresenham_bigger_up(data, point_b, point_a);
		else
			if (slope >= 1)
				bresenham_bigger_down(data, point_a, point_b);
			else
				bresenham_bigger_up(data, point_a, point_b);
	}
	else if (slope >= -1 && slope <= 1)
	{
		if (point_a.x >= point_b.x)
			bresenham_smaller(data, point_b, point_a);
		else
			bresenham_smaller(data, point_a, point_b);
	}
}
