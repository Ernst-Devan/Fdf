/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/10 22:58:02 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	<fcntl.h>
#include	"libft.h"
#include	"get_next_line.h"
#include	"utils.h"
#include	"stddef.h"

//! Set a default zoom to have no problem when i launch all maps
int	get_point_line(t_map *map, char *line)
{
	size_t	i;
	t_point	new_point;
	char	*endptr;

	i = 0;
	init_point(&new_point);
	while (i < map->memory_cols)
	{
		new_point.x = i;
		new_point.z = ft_strtol(line, &endptr, 10);
		if (line == endptr)
			return (1);
		line = endptr;
		if (*line == ',')
		{
			line++;
			new_point.color = ft_strtol(line, &endptr, 16);
		}
		line = endptr;
		while (ft_isspace(*line))
			line++;
		new_point.y = map->rows;
		map_add_point(map, new_point);
		i++;
	}
	return (0);
}

void	duplicate_map(t_map *basic, t_map *modified)
{
	size_t	i;

	i = 0;
	modified->points = malloc((basic->memory_rows) * sizeof(t_point*));
	//if (!modified->points)
	//	exiting();
	while (i < basic->memory_rows)
	{
		modified->points[i] = malloc((basic->memory_cols) * sizeof(t_point));
		//if (modified->points[i])
		//	exiting();
		i++;
	}
	i = 0;
	while (i < basic->memory_rows)
	{
		memlistcpy(basic->points[i], modified->points[i], basic->memory_cols);
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
		exit(4);
	}
	line = get_next_line(fd);
	win->basic.memory_cols = count_word(line);
	map_first_alloc(&win->basic);
	while(line != NULL)
	{
		if (get_point_line(&win->basic, line))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	duplicate_map(&win->basic, &win->modified);
	return (0);
}

