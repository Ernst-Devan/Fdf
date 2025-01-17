/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:55 by dernst            #+#    #+#             */
/*   Updated: 2025/01/16 13:06:14 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "libft.h"

void	parsing_map()
{
	int fd;
	int i;
	int j;
	char *line;
	char **map;
	
	// Size of BUFFERSIZE

	i = 0;
	j = 0;
	// Count before number of line present in the files so maybe need read one time before the 
	line = malloc(500 * sizeof(char *));
	fd = open("42.fdf", O_RDONLY);
	
	while (line != NULL)
	{	
		map[i] = malloc(ft_strlen(line) * sizeof(char));
		i++;
		line = get_next_line(fd);
	}	
	close(fd);
}