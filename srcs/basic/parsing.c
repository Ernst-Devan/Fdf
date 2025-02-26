/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/26 14:13:49 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"

int	get_point_line(t_map *map, char *line)
{
	size_t	i;
	t_point	new_point;
	char	*endptr;

	i = 0;
	while (i++ < map->memory_cols)
	{
		init_point(&new_point);
		new_point.x = i;
		new_point.z = ft_strtol(line, &endptr, 10);
		if (line == endptr)
			return (1);
		line = endptr;
		if (*line++ == ',')
			new_point.color = ft_strtol(line, &endptr, 16);
		line = endptr;
		new_point.y = map->rows;
		if (map_add_point(map, new_point))
			return (1);
	}
	return (0);
}

int	parsing_map(t_data *win)
{
	int		fd;
	char	*line;

	fd = open(win->fd_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\nThe map is not detected");
		exiting(win, NULL);
	}
	line = get_next_line(fd);
	if (!line)
		exiting(win, NULL);
	win->basic.memory_cols = count_word(line);
	if (map_first_alloc(&win->basic))
		exiting(win, line);
	while (line != NULL)
	{
		if (get_point_line(&win->basic, line))
			exiting(win, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	duplicate_map(win);
	return (0);
}
