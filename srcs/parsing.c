/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/01/22 16:19:33 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "libft.h"

// Detect overflow inside the map
// If overflow int don't accept the map
// Need to add the check if all the cols have the same size

int verif_map(const char *line, int *rows, int *cols)
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
			*cols += 1;
	}
	*rows += 1;
	return (0); 
}

int check_map()
{
	int fd;
	char *line;
	int rows;
	int cols;
	int verif;
	
	cols = 0;
	rows = 0;

	fd = open("42.fdf", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{	
		verif = verif_map(line, &rows, &cols);
		if (verif == 1)
			return(1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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

int get_map_value(t_map **map)
{

	int fd;
	char **splited_line;
	char *line;
	int i;
	int j;
	int rows;
	int cols;


	rows = 11;
	cols =  19;
	i = 0;
	j = 0;
	fd = open("42.fdf", O_RDONLY);
	line = get_next_line(fd);
	while (i < rows && line != NULL)
	{
		splited_line = ft_split(line, ' ');
		while (j < cols)
		{
			map[i][j].x = j + (50 *j);
			map[i][j].y = i + (100* i);
			map[i][j].z = ft_atoi(splited_line[j]);
			ft_printf("i: %d j:%d \n", i , j);
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

int	parsing_map(t_map **map)
{
	int i;

	i = 0;

	if (check_map() == 0)
	{
		get_map_value(map);
		
		return (0);
	}
	else 
		return (1);
}