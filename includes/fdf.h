/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:31:31 by dernst            #+#    #+#             */
/*   Updated: 2025/02/07 12:31:50 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "stddef.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

// STRUCTS
typedef struct	s_point {
	int	x;
	int	y;
	int	z;
	unsigned int color;
}		t_point;


typedef struct s_map {
	size_t	ishexa;
	size_t	cols;
	size_t	rows;
	size_t	memory_cols;
	size_t	memory_rows;
	size_t	total_rows;
	t_point	**points;
}		t_map;

typedef struct s_data {
	void	*img;
	void	*win_ptr;
	void	*mlx;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		status;
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
void	inital_window(char *map_name);
void	initial_program(t_data *window);


// Draw.c
void	put_pixel(t_data *data, int x, int y, int color);
void	isometrics_cordonate(t_data *win);
void	join_point(t_data *data);
void	choose_bresenham_algo(t_data *data, t_point point_a, t_point point_b);

// Parsing.c
int	parsing_map(t_data *win);
int	parsing_nb_line(t_data *win);

// Moving.c
int	move(t_data *win, int x, int y);
int zoom(t_data *win, double zoom);

#endif