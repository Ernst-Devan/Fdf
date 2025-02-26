/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:30 by dernst            #+#    #+#             */
/*   Updated: 2025/02/26 14:21:06 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

void	rotate_x(t_data *win, t_point *point)
{
	t_point	temp;
	
	init_point(&temp);
	temp.y = point->y;
	temp.z = point->z;
	point->y = cos(win->r_x) * temp.y - sin(win->r_x) * temp.z;
	point->z = sin(win->r_x) * temp.y + cos(win->r_x) * temp.z;
}

void	rotate_y(t_data *win, t_point *point)
{
	t_point	temp;

	init_point(&temp);
	temp.x = point->x;
	temp.z = point->z;
	point->z = -sin(win->r_y) * temp.x + cos(win->r_y) * temp.z;
	point->x = cos(win->r_y) * temp.x + sin(win->r_y) * temp.z;
}

void	rotate_z(t_data *win, t_point *point)
{
	t_point	temp;

	init_point(&temp);
	temp.x = point->x;
	temp.y = point->y;
	point->x = cos(win->r_z) * temp.x - sin(win->r_z)
		* temp.y;
	point->y = sin(win->r_z) * temp.x + cos(win->r_z)
		* temp.y;
}
