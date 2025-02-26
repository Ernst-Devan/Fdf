/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:47:10 by dernst            #+#    #+#             */
/*   Updated: 2025/02/26 14:17:30 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "fdf.h"
#include <mlx.h>

int	key_factor(int key, t_data *win)
{
	if (key == XK_o)
		win->factor_z += Z_ZOOM;
	if (key == XK_l)
		win->factor_z -= Z_ZOOM;
	return (1);
}

int	key_move(int key, t_data *win)
{
	if (key == XK_d)
		win->m_x += MOVE;
	if (key == XK_a)
		win->m_x -= MOVE;
	if (key == XK_w)
		win->m_y -= MOVE;
	if (key == XK_s)
		win->m_y += MOVE;
	return (1);
}

int	key_rotate(int key, t_data *win)
{
	if (key == K_9)
		win->r_x += 0.1;
	if (key == K_7)
		win->r_x -= 0.1;
	if (key == K_6)
		win->r_y += 0.1;
	if (key == K_4)
		win->r_y -= 0.1;
	if (key == K_3)
		win->r_z += 0.1;
	if (key == K_1)
		win->r_z -= 0.1;
	return (1);
}

int	handle_keypress(int key, t_data *win)
{
	size_t	allowed_keys;

	allowed_keys = 0;
	if (key == XK_Escape)
		exiting(win, NULL);
	if (key == XK_d || key == XK_a || key == XK_s || key == XK_w)
		if (key_move(key, win))
			allowed_keys = 1;
	if (key == K_7 || key == K_9 || key == K_4 || key == K_6
		|| key == K_1 || key == K_3)
		if (key_rotate(key, win))
			allowed_keys = 1;
	if (key == XK_o || key == XK_l || key == XK_t || key == XK_y)
		if (key_factor(key, win))
			allowed_keys = 1;
	if (allowed_keys == 1)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, W_WIDTH, W_HEIGHT);
		apply_projection(win);
		mlx_put_image_to_window(win->mlx, win->win_ptr, win->img, 0, 0);
	}
	return (0);
}

int	handle_mouse(int key, int x, int y, t_data *win)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, W_WIDTH, W_HEIGHT);
		if (key == 4)
			win->f_scale *= ZOOM_IN;
		if (key == 5)
			win->f_scale *= ZOOM_OUT;
		apply_projection(win);
		mlx_put_image_to_window(win->mlx, win->win_ptr, win->img, 0, 0);
	}
	return (0);
}
