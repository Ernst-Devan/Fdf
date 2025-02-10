/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:48 by dernst            #+#    #+#             */
/*   Updated: 2025/02/10 17:21:19 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"


//! Problem when the line is totaly right
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
	while ((x <= point_b.x && ((x <= 1920 && x >= 0) && (y <= 1080 && y >= 0))))
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

void	bresenham_bigger(t_data *data, t_point point_a, t_point point_b)
{
	int	x;
	int	y;
	int	P;
	int	stepx;
	int stepy;

	if (point_b.x >= point_a.x)
		stepx = 1;
	else
		stepx = -1;
	if (point_b.y >= point_a.y)
		stepy = 1;
	else
		stepy = -1;
	x = point_a.x;
	y = point_a.y;
	P = 2 * (abs_value(point_b.x - point_a.x) - abs_value(point_b.y - point_a.y));
	while (y != point_b.y)
	{
		put_pixel(data, x, y, point_b.color);
		y += stepy;
		if (P < 0)
			P +=  2 * (abs_value(point_b.x - point_a.x));
		else
		{
			x += stepx;
			P +=  2 * (abs_value(point_b.x - point_a.x) - abs_value(point_b.y - point_a.y));
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
			bresenham_bigger(data, point_a, point_b);
		else
			bresenham_bigger(data, point_b, point_a);
	}
	else if (slope >= -1 && slope <= 1)
	{
		if (point_a.x >= point_b.x)
			bresenham_smaller(data, point_b, point_a);
		else
			bresenham_smaller(data, point_a, point_b);
	}
}
