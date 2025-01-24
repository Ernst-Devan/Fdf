/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:31:31 by dernst            #+#    #+#             */
/*   Updated: 2025/01/23 12:58:17 by dernst           ###   ########lyon.fr   */
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
	int		width;
	int		lenght;
}		t_data;

typedef struct s_line {
	int	**line;
	int size;
}		t_line;

typedef struct	s_map {
	int x;
	int y;
	int z;
	char color;
}		t_map;

// Fdf.c
void put_pixel(t_data *data, int x, int y, int color);

// Window.c
void inital_window();
void initial_program(t_data *window);

// Parsing.c
int parsing_map(t_map ***map, int *rows, int *cols);
int check_map(int *rows, int *cols);
int count_cols(char **splited_line);
int count_word(char *line);
int verif_map(const char *line);
void get_map_value(t_map **map, int *rows, int *cols);

// Draw.c
void bresenham_algorithm(t_data *data, int Ax, int Ay, int Bx, int By);
void isometrics_cordonate(t_data *window, t_map **map, int *rows, int *cols);
void join_point(t_data *data, t_map **map, int cols, int rows);

// Error.c
void error_management(t_map **map);
void cleanup(t_map **map, int index_allocated);

#endif