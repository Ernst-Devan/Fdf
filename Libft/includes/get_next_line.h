/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:52 by dernst            #+#    #+#             */
/*   Updated: 2025/01/20 22:44:28 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// get_next_line_utils
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_substr(char *s, size_t len, size_t *is_end, size_t *buffer_start);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_gnl(const char *str, int type);
void	*ft_calloc(size_t nmemb, size_t size);
char	*null_free(char **str);

#endif