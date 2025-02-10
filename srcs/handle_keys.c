/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:47:10 by dernst            #+#    #+#             */
/*   Updated: 2025/02/10 22:54:56 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/X.h>
#include "fdf.h"
#include <mlx.h>

void	manage_hook(t_data win)
{
	mlx_hook(win.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &win);
	mlx_hook(win.win_ptr, DestroyNotify, NoEventMask, &handle_window, &win);
	mlx_hook(win.win_ptr, ButtonPress, ButtonPressMask, &handle_mouse, &win);
}

int	handle_keypress(int key, t_data *win)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(win->mlx, win->win_ptr);
		exiting(win);
	}
	if (key == XK_d || key == XK_a || key == XK_s || key == XK_w || key == XK_o || key == XK_l)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, W_WIDTH, W_HEIGHT);
		if (key == XK_d)
			win->move_x += MOVE;
		if (key == XK_a)
			win->move_x -= MOVE;
		if (key == XK_w)
			win->move_y -= MOVE;
		if (key == XK_s)
			win->move_y += MOVE;
		if (key == XK_o)
			win->factor_z += Z_ZOOM;
		if (key == XK_l)
			win->factor_z -= Z_ZOOM;
		apply_projection(win);
		mlx_put_image_to_window(win->mlx, win->win_ptr, win->img, 0, 0);
	}
	return (0);
}

int	handle_mouse(int key, int x, int y, t_data *win)
{
	if (key == 4 || key == 5)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, W_WIDTH, W_HEIGHT);
		if (key == 4)
			win->factor_scale *= ZOOM_IN;
		if (key == 5)
			win->factor_scale *= ZOOM_OUT;
		apply_projection(win);
		mlx_put_image_to_window(win->mlx, win->win_ptr, win->img, 0, 0);
	}
	return (0);
}

int	handle_window(t_data *win)
{
	mlx_destroy_window(win->mlx, win->win_ptr);
	exiting(win);
	return (0);
}