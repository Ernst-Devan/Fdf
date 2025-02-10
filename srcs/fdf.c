/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:45:05 by dernst            #+#    #+#             */
/*   Updated: 2025/02/10 22:56:01 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// ![] DONT FORGET TO ADD FLAGS DURINT THE COMPILATION
// ![] ALL RETURN POINTER MUST BE CHECKED IF THEY RETURN NULL
// ![] DO THE ERROR MANAGEMENT
// ![] CHECK ALL FREE ARE DO SAME FOR FUNCTION OF THE LIBFT

#include "libft.h"
#include "fdf.h"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_printf("Too many arguments inside the ./fdf\n");
		return(3);
	}
	if (argc == 2)
	{
		ft_printf("Map Selected : %s", argv[1]);
		initial_window(argv[1]);
	}
	else
	{
		ft_printf("Default Map : 42");
		initial_window(NULL);
	}
	return (0);	
}
