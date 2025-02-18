/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:48 by dernst            #+#    #+#             */
/*   Updated: 2025/02/18 17:12:36 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"
#include <stdio.h>

void	bresenham_smaller(t_data *data, t_point a, t_point b)
{
	int	x;
	int	y;
	int	p;
	int	step;
	if (b.y >= a.y)
		step = 1;
	else
		step = -1;
	x = a.x;
	y = a.y;
	p = 2 * (abs_value(b.y - a.y) - abs_value (b.x - a.x));
	while (x <= b.x)
	{
		if (x >= 1920)
			x++;
		else
		{	
			put_pixel(data, x, y, b.color);
			x++;
			if (p < 0)
				p = p + 2 * (abs_value (b.y - a.y));
			else
			{
				p = p + 2 * (abs_value (b.y - a.y)) - 2 *(abs_value (b.x - a.x));
				y += step;
			}
		}
	}
}

void	bresenham_bigger(t_data *data, t_point a, t_point b)
{
	int	x;
	int	y;
	int	p;
	int	stepx;
	int	stepy;

	if (b.x >= a.x)
		stepx = 1;
	else
		stepx = -1;
	if (b.y >= a.y)
		stepy = 1;
	else
		stepy = -1;
	x = a.x;
	y = a.y;
	p = 2 * (abs_value(b.x - a.x) - abs_value(b.y - a.y));
	if (y >= 1080)
	while (y != b.y)
	{
		if (y >= 1080)
			y += stepy;
		else
		{			
			put_pixel(data, x, y, b.color);
			y += stepy;
			if (p < 0)
				p += 2 * (abs_value(b.x - a.x));
			else
			{
				x += stepx;
				p += 2 * (abs_value(b.x - a.x) - abs_value(b.y - a.y));
			}
		}
	}
}

void	choose_bresenham_algo(t_data *data, t_point point_a, t_point point_b)
{
	int	slope;

	if (point_b.x == point_a.x)
	{
		if (point_a.y > point_b.y)
			bresenham_bigger(data, point_b, point_a);
		else
			bresenham_bigger(data, point_a, point_b);
		return ;
	}
	slope = (point_b.y - point_a.y) / (point_b.x - point_a.x);
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
