/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:31:31 by dernst            #+#    #+#             */
/*   Updated: 2025/02/14 15:45:36 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "stddef.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define Z_ZOOM 0.1
# define ZOOM_OUT 0.9
# define ZOOM_IN 1.1
# define MOVE 10
# define ISO 0.523599
# define PI 3.14159265358979323846
# define K_7 65429
# define K_9 65434
# define K_4 65430
# define K_6 65432
# define K_1 65436
# define K_3 65435

// STRUCTS
typedef struct	s_point {
	int	x;
	int	y;
	int	z;
	unsigned int color;
}		t_point;

typedef struct s_map {
	size_t	cols;
	size_t	rows;
	size_t	memory_cols;
	size_t	memory_rows;
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
	char	*fd_map;
	float	factor_scale;
	float	r_x;
	float	r_y;
	float	r_z;
	int		m_x;
	int		m_y;
	int		projection;
	float	factor_z;
	t_map	basic;
	t_map	modified;
}		t_data;

// Vector.c
int		map_first_alloc(t_map *map);
int		map_add_point(t_map *map, t_point point);
void	memlistcpy(t_point *rows, t_point *new_rows, size_t n);

// Init.c
void	init_data(t_data *win);
void	init_point(t_point *point);

// Window.c
void	initial_window(char *map_name);
void	initial_program(t_data *window);

// Draw.c
void	apply_projection(t_data *win);
void	put_pixel(t_data *data, int x, int y, int color);
void	point_projection(t_data *win);
void	join_point(t_data *data);
void	choose_bresenham_algo(t_data *data, t_point point_a, t_point point_b);

// Handle_keys.c
void	manage_hook(t_data *win);
int		handle_keypress(int key, t_data *win);
int		handle_mouse(int key, int x, int y, t_data *win);
int		handle_window(t_data *win);

// Error.c
void	exiting(t_data *win);
void	cleanup(t_map *map);

// Rotation.c
void	rotate_x(t_data *win, t_point *point);
void	rotate_y(t_data *win, t_point *point);
void	rotate_z(t_data *win, t_point *point);

// Parsing.c
int	parsing_map(t_data *win);
//int	parsing_nb_line(t_data *win);

#endif