/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:31:31 by dernst            #+#    #+#             */
/*   Updated: 2025/01/30 23:03:34 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "stddef.h"

// STRUCTS
typedef struct	s_point {
	size_t x;
	size_t y;
	int z;
	unsigned int color;
}		t_point;


typedef struct s_map {
	size_t	ishexa;
	size_t	cols;
	size_t	rows;
	size_t	memory_cols;
	size_t	memory_rows;
	t_point	**points;
}		t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		status;
	int		width;
	int		lenght;
	char	*fd_map;
	t_map 	map;
}		t_data;

// Vector.c
void	map_first_alloc(t_data *win);
void	map_add_point(t_data *win, t_point point);

// Init.c
void	init_data(t_data *win);
void	init_point(t_point *point);


// Window.c
void inital_window(char *map_name);
void initial_program(t_data *window);


// Draw.c
void put_pixel(t_data *data, int x, int y, int color);
void bresenham_algorithm(t_data *data, int Ax, int Ay, int Bx, int By);
void isometrics_cordonate(t_data *win);
void join_point(t_data *data, t_map **map, int cols, int rows);

// Parsing.c
int	parsing_map(t_data *win);



#endif