/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:53:24 by dernst            #+#    #+#             */
/*   Updated: 2025/02/04 11:50:14 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

char	*atoi_part(char *s, t_limits *lim, size_t *ac, int *any)
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
	return (s);
}

void	manage_pointer(char **endptr, const char *nptr, int any, char *s)
{
	if (*endptr != NULL)
	{
		if (any)
			*endptr = s;
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
	s = atoi_part((char *)s, &limits, &acc, &any);
	if (any < 0)
	{
		if (limits.neg)
			acc = LONG_MIN;
		else
			acc = LONG_MAX;
	}
	else if (limits.neg)
		acc = -acc;
	manage_pointer(endptr, nptr, any, (char *)s);
	return (acc);
}