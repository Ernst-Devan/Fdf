/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:55 by dernst            #+#    #+#             */
/*   Updated: 2025/01/28 13:57:34 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//! ADD this function inside the Libft And Secure them
#include "stddef.h"

size_t	ft_ishexa(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102))
		return (1);
	return (0);
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