/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:06:52 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/11/12 00:49:51 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (s1[j] && ft_strlen(s1))
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] && ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
