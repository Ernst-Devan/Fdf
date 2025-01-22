/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:54 by dernst            #+#    #+#             */
/*   Updated: 2025/01/21 12:09:37 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	error_management(t_map **map)
{
	int i;
	
	i = 0;
	while (i < map[0][0].x)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
	exit(1);
}

void cleanup(t_map **map, int index_allocated)
{
	int i;
	
	i = 0;
	while (i > index_allocated)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
}