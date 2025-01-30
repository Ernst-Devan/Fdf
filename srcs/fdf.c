/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:45:05 by dernst            #+#    #+#             */
/*   Updated: 2025/01/28 14:31:02 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// ![] DONT FORGET TO ADD FLAGS DURINT THE COMPILATION
// ![] ALL RETURN POINTER MUST BE CHECKED IF THEY RETURN NULL
// ![] PROTECT NEGATIVE NUMBER INSIDE A PUT PIXEL
// ![] CLOSE THE WINDOW WHITH THE CROSS AND ECHAP
// ![] CHECK IF WE CAN USE THE EXIT FUNCTION TO ESCAPE FROM EACH FUNCTION WITH FAILED MALLOC FOR EXEMPLE
// ![] DO THE ERROR MANAGEMENT
// [] REMOVE THE FUNCTION ABS AND REMAKE IT 
// ![] CHECK ALL FREE ARE DO SAME FOR FUNCTION OF THE LIBFT

#include "libft.h"
#include "fdf.h"
#include <mlx.h>


char	*selected_map(char *map_file)
{
	char	*full_path;

	full_path = malloc(6 * sizeof(char));
	if (!full_path)
		exit(1);
	ft_memcpy(full_path, "maps/", 6);
	ft_strlcat(full_path, map_file, ft_strlen(map_file) + 6);
	ft_strlcat(full_path, ".fdf", ft_strlen(full_path) + 5);
	return(full_path);
}

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
		inital_window(selected_map(argv[1]));
	}
	else
	{
		ft_printf("Default Map : 42");
		inital_window(NULL);
	}
	return (0);	
}
