/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/01/24 16:22:19 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "libft.h"

// Detect overflow inside the map
// If overflow int don't accept the map
// Manage the hexadecimal number for the atoi and the parsing so i can't just check if i detect a string it's not always a invalid map
// Refaire le readme en meilleur dcp vu que j'ai tout perdu aprceque je suis con

//! IF 0X inside the map it's correspond to the colors and check they have only 6 number after
//! if hexa inside the map check the placement of the ',' 

int verif_map(const char *line)
{
	int i;
	int	size;
	int n;
	i = 0;
	n = 0;
	
	size = ft_strlen(line);
	while(i < size)
	{	
		
		if (line[i] == '-' && ft_isdigit(line[i + 1]) == 0)
			return (1);
		else if (line[i] == '-')
			i++;
		if (line[i] == 0 && line[i + 1] == 'x' && i < size)
		{
			i += 2;
			while (n < 6)
			{
				if (ft_isdigit(line[i]) == 0)
					return(1);
				n++;
				i++;
			}
		}
		else
		{
			while (ft_isdigit(line[i]) == 1)
				i++;
		}
		if (line[i] != ','  && i != size - 1 && line[i] != '\0')
			return (1);
		i++;
	}
	return (0); 
}

int count_word(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
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

int count_cols(char **splited_line)
{
	int i;

	i = 0;
	while (splited_line[i] != NULL)
		i++;
	return (i);
}

// Check open verif
int check_map(int *rows, int *cols)
{
	int fd;
	char *line;
	int verif;
	
	fd = open("julia.fdf", O_RDONLY);
	//ft_printf("%d", fd);
	line = get_next_line(fd);
	if (!line)
		return (1);
	*cols = count_word(line);
	while (line != NULL)
	{	
		verif = verif_map(line);
		if (verif == 1)
			return(1);
		free(line);
		line = get_next_line(fd);
		if (line)
			if (count_word(line) != *cols)
				return (1);
		*rows += 1;
	}
	close(fd);
	return (0);
}


void get_map_value(t_map **map, int *rows, int *cols)
{

	int fd;
	char **splited_line;
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open("julia.fdf", O_RDONLY);
	line = get_next_line(fd);
	while (i < *rows && line != NULL)
	{
		splited_line = ft_split(line, ' ');
		while (j < *cols)
		{
			map[i][j].x = j + ( 20 *j);
			map[i][j].y = i + (20* i);
			map[i][j].z = ft_atoi(splited_line[j]) * 10; 
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
