/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:47:10 by dernst            #+#    #+#             */
/*   Updated: 2025/02/20 18:08:17 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/X.h>
#include "fdf.h"
#include <mlx.h>
#include "libft.h"

void	manage_hook(t_data *win)
{
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, &handle_keypress, win);
	mlx_hook(win->win_ptr, DestroyNotify, NoEventMask, &handle_window, win);
}

int	handle_keypress(int key, t_data *win)
{
	size_t	allowed_keys;

	allowed_keys = 0;
	if (key == XK_Escape)
		exiting(win);
	return (0);
}

int	handle_window(t_data *win)
{
	exiting(win);
	return (0);
}
