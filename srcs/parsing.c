/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/01/27 18:05:36 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	<fcntl.h>
#include	"libft.h"
#include	"utils.h"

// Detect overflow inside the map
// If overflow int don't accept the map
// Manage the hexadecimal number for the atoi and the parsing so i can't just check if i detect a string it's not always a invalid map

//! IF 0X inside the map it's correspond to the colors and check they have only 6 number after
//! if hexa inside the map check the placement of the ',' 

int	parsing_map(t_data *win)
{
	int		fd;
	char	*line;
	t_point test_point;

	fd = open("julia.fdf", O_RDONLY);
	line = get_next_line(fd);
	win->map.memory_cols = count_word(line);
	map_first_alloc(win);
	if(line[0] == ' ')
		win->map.ishexa = 1;
	ft_printf("ishexa : %d", win->map.ishexa);
	while(line != NULL)
	{
		if (check_map(win, line))
			return (2);
		//get_point_line()
		line = get_next_line(fd);
	}
	return (0);
}

//TODO 
int check_hexa_map(t_data, char *line)
{
	
}

int check_map(t_data *win, char *line)
{
	if(win->map.ishexa)
		
	return (0);
}

void	get_point_line(t_data *win, char *line)
{
	
}
