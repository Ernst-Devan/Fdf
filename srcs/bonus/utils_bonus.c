/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/25 18:09:08 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "libft.h"
#include "fdf.h"

int	abs_value(int x)
{
	if (x < 0)
	{
		return (x * -1);
	}
	return (x);
}

int	count_word(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0' || line[i] == '\n')
	{
		while (line[i] == ' ' && line[i] != '\0')
			i++;
		while (line[i] > 32 && line[i] != '\0')
			i++;
		if (line[i - 1] > 32)
			count++;
		i++;
	}
	return (count);
}

void	duplicate_map(t_data *win)
{
	size_t	i;

	i = 0;
	win->modified.points = malloc((win->basic.memory_rows) * sizeof(t_point *));
	if (!win->modified.points)
		exiting(win);
	while (i < win->basic.memory_rows)
	{
		win->modified.points[i]
			= malloc((win->basic.memory_cols) * sizeof(t_point));
		if (!win->modified.points[i])
			exiting(win);
		i++;
	}
	i = 0;
	while (i < win->basic.memory_rows)
	{
		memlistcpy(win->basic.points[i],
			win->modified.points[i], win->basic.memory_cols);
		i++;
	}
	win->modified.cols = win->basic.cols;
	win->modified.rows = win->basic.rows;
	win->modified.memory_cols = win->basic.memory_cols;
	win->modified.memory_rows = win->basic.memory_rows;
}
