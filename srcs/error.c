/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:54 by dernst            #+#    #+#             */
/*   Updated: 2025/01/20 21:50:11 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	error_management(t_pair **Pair)
{
	int i;
	
	i = 0;
	while (i < Pair[0][0].x)
	{
		if (Pair[i])
			free(Pair[i]);
		i++;
	}
	if (Pair)
		free(Pair);
	exit(1);
}

void cleanup(t_pair **map, int index_allocated)
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