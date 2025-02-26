/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:48 by dernst            #+#    #+#             */
/*   Updated: 2025/02/26 14:16:10 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

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

void	define_step(int	*stepx, int *stepy, t_point a, t_point b)
{
	if (b.x >= a.x)
		*stepx = 1;
	else
		*stepx = -1;
	if (b.y >= a.y)
		*stepy = 1;
	else
		*stepy = -1;
}

void	bresenham_bigger(t_data *data, t_point a, t_point b)
{
	int	x;
	int	y;
	int	p;
	int	stepx;
	int	stepy;

	define_step(&stepx, &stepy, a, b);
	x = a.x;
	y = a.y;
	p = 2 * (abs_value(b.x - a.x) - abs_value(b.y - a.y));
	while (y != b.y)
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

void	swap(t_data *data, t_point *a, t_point *b, int issmaler)
{
	unsigned long int	temp;

	temp = b->color;
	b->color = a->color;
	a->color = temp;
	if (issmaler)
		bresenham_smaller(data, *b, *a);
	else
		bresenham_bigger(data, *b, *a);
}

void	choose_bresenham_algo(t_data *data, t_point a, t_point b)
{
	int	slope;

	if (b.x == a.x)
	{
		if (a.y > b.y)
			swap(data, &a, &b, 0);
		else
			bresenham_bigger(data, a, b);
		return ;
	}
	slope = (b.y - a.y) / (b.x - a.x);
	if (slope >= 1 || slope <= -1)
	{
		if (a.x >= b.x)
			bresenham_bigger(data, a, b);
		else
			swap(data, &a, &b, 0);
	}
	else if (slope >= -1 && slope <= 1)
	{
		if (a.x >= b.x)
			swap(data, &a, &b, 1);
		else
			bresenham_smaller(data, a, b);
	}
}
