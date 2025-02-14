/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/14 15:28:44 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	<fcntl.h>
#include	"libft.h"
#include	"get_next_line.h"
#include	"utils.h"
#include	"stddef.h"

//! Set a default zoom to have no problem when i launch all maps
void	get_point_line(t_map *map, char *line)
{
	size_t	i;
	t_point	new_point;
	char	*endptr;
	unsigned long int color;

	i = 0;
	endptr = NULL;
	init_point(&new_point);
	while (i < map->memory_cols)
	{
		new_point.x = i;
		new_point.z = ft_strtol(line, &endptr, 10);
		if (line == endptr)
			return;
		line = endptr;
		if (*line == ',')
		{
			line++;
			new_point.color = ft_strtol(line, &endptr, 16);
			color = new_point.color;
		}
		line = endptr;
		while (line && ft_isspace(*line))
			line++;
		new_point.y = map->rows;
		if (map_add_point(map, new_point))
			return;
		i++;
	}
}


int	parsing_map(t_data *win)
{
	int		fd;
	char	*line;

	fd = open(win->fd_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\nThe map is not detected");
		exiting(win);
	}
	line = get_next_line(fd);
	if (!line)
		exiting(win);
	win->basic.memory_cols = count_word(line);
	if (map_first_alloc(&win->basic))
		exiting(win);
	while(line != NULL)
	{
		get_point_line(&win->basic, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	duplicate_map(win);
	return (0);
}

