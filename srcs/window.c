/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:42:43 by dernst            #+#    #+#             */
/*   Updated: 2025/01/31 22:20:17 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "limits.h"
#include "errno.h"
#include "libft.h"

const char	*start_manage(const char *nptr, t_limits *limits)
{
	const char	*s;

	limits->neg = 0;
	s = nptr;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		limits->neg = (*s == '-');
		s++;
	}
	limits->coff = LONG_MAX;
	if (limits->neg)
		limits->coff = -(unsigned long)LONG_MIN;
	if (limits->base == 16 && limits->c == '0' && (*s == 'x' || *s == 'X'))
	{
		limits->c = s[1];
		s += 2;
	}
	limits->clim = limits->coff % (unsigned long)limits->base;
	limits->coff /= (unsigned long)limits->base;
	return (s);
}

void	atoi_part(char *s, t_limits *lim, size_t *ac, int *any)
{
	int	digit;
	
	while (*s)
	{
		if (ft_isdigit(*s))
			digit = *s - '0';
		else if (ft_isalpha(*s))
			digit = ft_toupper(*s) - 'A' + 10;
		else
			break ;
		if (digit >= lim->base)
			break ;
		if (*any < 0 || *ac > lim->coff || (*ac == lim->coff && lim->c > lim->clim))
		{
			*any = -1;
			break;
		}	
			*any = 1;
			*ac = *ac * lim->base + digit;
		s++;
	}
}

void	manage_pointer(char **endptr, const char *nptr, int any, char *s)
{
	if (endptr != NULL)
	{
		if (any)
			*endptr = (char *) s;
		else
			*endptr = (char *)nptr;
	}
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	t_limits		limits;
	const char		*s;
	size_t			acc;
	int				any;

	limits.base = base;
	s = start_manage(nptr, &limits);
	acc = 0;
	any = 0;
	atoi_part((char *)s, &limits, &acc, &any);
	if (any < 0)
	{
		if (limits.neg)
			acc = LONG_MIN;
		else
			acc = LONG_MAX;
	}
	else if (limits.neg)
		acc = -acc;
	manage_pointer(endptr, nptr, any, s);
	return (acc);
}


void initial_program(t_data *win)
{
	//parsing_map(win);
	//isometrics_cordonate(win);
	char	*endptr;
	long	number;
	number = ft_strtol("10", &endptr, 10);
	ft_printf("\n%d",number);
}

void inital_window(char *map_name)
{
	void	*mlx;
	t_data	win;
	void	*mlx_win;

	mlx = mlx_init();
	init_data(&win);
	if (map_name)
		win.fd_map = map_name;
	win.width = 1920;
	win.lenght = 1080;
	mlx_win = mlx_new_window(mlx, win.width, win.lenght, "Fdf");
	win.img = mlx_new_image(mlx, win.width, win.lenght);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_lenght, &win.endian);
	initial_program(&win);
	mlx_put_image_to_window(mlx, mlx_win, win.img, 0, 0);
	mlx_loop(mlx);
}
