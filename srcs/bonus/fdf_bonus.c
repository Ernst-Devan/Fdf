/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:45:05 by dernst            #+#    #+#             */
/*   Updated: 2025/02/20 17:54:53 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	win;

	init_data(&win);
	if (argc > 2)
	{
		ft_printf("Too many arguments inside the ./fdf\n");
		return (3);
	}
	if (argc == 2)
	{
		ft_printf("Map Selected : %s", argv[1]);
		initial_window(&win, argv[1]);
	}
	else
	{
		ft_printf("Default Map : 42");
		initial_window(&win, NULL);
	}
	return (0);
}
