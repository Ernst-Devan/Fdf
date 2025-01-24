/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:45:05 by dernst            #+#    #+#             */
/*   Updated: 2025/01/24 15:46:35 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// [] DO IN PAPER ALL STEP NEED TO ACHIEVE TO FINISH THIS PROJECT

// [x] MAKE A GIT REPOSITORY
// [x] ADD LIBFT
// [x] UNDERSTAND HOW WORK MINLIBX
// [x] INSTALL MINLIBX INSIDE THE PROJECT
// ![] DONT FORGET TO ADD FLAGS DURINT THE COMPILATION
// [x] MAKE A WINDOWS 
// ![] MAKE THE GRID
// ![] ALL RETURN POINTER MUST BE CHECKED IF THEY RETURN NULL
// ![] PROTECT NEGATIVE NUMBER INSIDE A PUT PIXEL
// ![] CLOSE THE WINDOW WHITH THE CROSS AND ECHAP
// ![] TO JOIN POINT WE NEED TO MAKE A MAP OF EACH POINT PLACED WITH HIS LOCATION LIKE THIS
// ![] CHECK IF WE CAN USE THE EXIT FUNCTION TO ESCAPE FROM EACH FUNCTION WITH FAILED MALLOC FOR EXEMPLE
// ![] DO THE ERROR MANAGEMENT
// [] REMOVE THE FUNCTION ABS AND REMAKE IT 
// ![] CHECK ALL FREE ARE DO SAME FOR FUNCTION OF THE LIBFT




#include "libft.h"
#include "fdf.h"
#include <mlx.h>

void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	
	inital_window();
	
}
