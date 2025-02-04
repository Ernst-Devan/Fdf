/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/04 16:05:14 by dernst           ###   ########lyon.fr   */
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
// Manage the hexadecimal number for the atoi and the parsing so i can't just check if i detect a string it's not always a invalid map

//! IF 0X inside the map it's correspond to the colors and check they have only 6 number after
//! if hexa inside the map check the placement of the ',' 
// Manage the return error

//TODO 

void	display_point(t_data *win)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < win->map.memory_rows)
	{
		while (j < win->map.memory_cols)
		{
			ft_printf("y:%d ", win->map.points[i][j].y);
			ft_printf("x:%d \n", win->map.points[i][j].x);
			j++;
		}
		j = 0;
		i++;
	}
}

int	detect_hexa(char *line)
{
	char		c;
	const char 	*s;

	s = line;
	if(s[0] == '0' && s[1] == 'x')
		return(1);
	return (0); 
}

int	get_point_line(t_data *win, char *line)
{
	size_t	i;
	t_point	new_point;
	char	*endptr;

	i = 0;
	while (i < win->map.memory_cols)
	{
		new_point.x = i * 40;
		new_point.z = ft_strtol(line, &endptr, 10);
		if (line == endptr)
			return (1);
		while (ft_isspace(*line))
			line++;
		if (*line == ',')
		{
			ft_printf("test");
			line++;
			new_point.color = ft_strtol(line, &endptr, 16);
		}
		new_point.y = win->map.rows * 40;
		map_add_point(win, new_point);
		line = endptr;
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
	win->map.memory_cols = count_word(line);
	map_first_alloc(win);
	while(line != NULL)
	{
		if (get_point_line(win, line))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

