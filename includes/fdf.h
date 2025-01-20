/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:31:31 by dernst            #+#    #+#             */
/*   Updated: 2025/01/20 21:47:47 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// STRUCTS

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		status;
}		t_data;

typedef struct s_line {
	int	**line;
	int size;
}		t_line;

typedef struct s_pair {
	int x;
	int y;
}	t_pair;

// Fdf.c
void put_pixel(t_data *data, int x, int y, int color);

// Parsing.c
void parsing_map();

// Draw.c
void bresenham_algorithm(t_data *data, int Ax, int Ay, int Bx, int By);
void create_grid_square(t_data *data, int x, int y, t_pair **map);
void join_point(t_data *data, t_pair **Pair, int cols, int rows);

// Error.c
void error_management(t_pair **Pair);
void cleanup(t_pair **map, int index_allocated);

#endif