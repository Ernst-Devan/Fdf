/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/09 17:06:05 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	<fcntl.h>
#include	"libft.h"
#include	"get_next_line.h"
#include	"utils.h"
#include	"stddef.h"
// Detect overflow inside the map
// If overflow int don't accept the map
// Manage the return error

//! Set a default zoom to have no problem when i launch all maps
//! Floating point exception with ./fdf.out pyramide

//int	parsing_nb_line(t_data *win)
//{
//	int		fd;
//	char	*line;
//	int		count;

//	count = 0;
//	fd = open(win->fd_map, O_RDONLY);
//	if (fd < 0)
//	{
//		ft_printf("\nThe map is not detected");
//		return (1);
//	}
//	line = get_next_line(fd);
//	while(line != NULL)
//	{
//		count++;
//		free(line);
//		line = get_next_line(fd);
//	}
//	win->map.total_rows = count;
//	close(fd);
//	return (0);
//}

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
	return (0);
}

