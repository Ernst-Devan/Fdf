/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/01/22 18:26:03 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

// Detect overflow inside the map
// If overflow int don't accept the map
// Need to add the check if all the cols have the same size

int verif_map(const char *line)
{
	int i;
	i = 0;
	while(i < ft_strlen(line))
	{	
		if (line[i] == '-' && ft_isdigit(line[i + 1]) == 0)
			return (1);
		else if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]) == 1)
			i++;
		if (line[i] != ' ' && i != ft_strlen(line) - 1)
			return (1);
		i++;
	}
	return (0); 
}

int count_cols(char **splited_line)
{
	int i;

	i = 0;
	while (splited_line[i] != NULL)
		i++;
	return (i);
}

// The checker of cols don't work
int check_map(int *rows, int *cols)
{
	int fd;
	char *line;
	char **splited_line;
	int verif;
	
	fd = open("42.fdf", O_RDONLY);
	line = get_next_line(fd);
	splited_line = ft_split(line, ' ');
	*cols = count_cols(splited_line);
	ft_printf("DEFINED COLS: %d\n", *cols);
	while (line != NULL)
	{	
		verif = verif_map(line);
		if (verif == 1)
			return(1);
		free(splited_line);
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			splited_line = ft_split(line, ' ');
			if (count_cols(splited_line) != *cols)
			{
				return (1);
			}
		}
		*rows += 1;
	}
	close(fd);
	return (0);
}


int get_map_value(t_map **map, int *rows, int *cols)
{

	int fd;
	char **splited_line;
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open("42.fdf", O_RDONLY);
	line = get_next_line(fd);
	while (i < *rows && line != NULL)
	{
		splited_line = ft_split(line, ' ');
		while (j < *cols)
		{
			map[i][j].x = j + (50 *j);
			map[i][j].y = i + (100* i);
			map[i][j].z = ft_atoi(splited_line[j]);
			j++;
		}
		i++;
		j = 0;
		free(line);
		free(splited_line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	parsing_map(t_map **map, int *rows, int *cols)
{
	int i;

	i = 0;
	if (check_map(rows, cols) == 0)
	{
		//ft_printf(" cols : !%d! rows: !%d!\n", *cols,*rows);
		//get_map_value(map, rows, cols);
		
		return (0);
	}
	else 
		return (1);
}