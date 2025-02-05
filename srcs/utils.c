/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:55 by dernst            #+#    #+#             */
/*   Updated: 2025/02/05 17:43:28 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//! ADD this function inside the Libft And Secure them
#include "stddef.h"
#include "libft.h"
#include "fdf.h"

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

int abs_value(int x)
{
	if(x < 0)
	{
		return(x * -1);
	}
	return (x);
}

int count_word(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0' || line[i] == '\n')
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