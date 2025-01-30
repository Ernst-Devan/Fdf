/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:07:56 by ernstdevan        #+#    #+#             */
/*   Updated: 2025/01/30 22:40:47 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//=======================================
// Include Dependancies
//=======================================

# include "stdlib.h"
# include "limits.h"
# include "unistd.h"

//=======================================
// Functions Prototypes
//=======================================

	// FT_IS
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);

	// FT_STR
	//=======================================

typedef struct s_limits
{
	int		c;
	int		clim;
	int		neg;
	size_t	coff;
	int		base;
}	t_limits;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_strtol(const char *nptr, char **endptr, int base);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_bzero(void *s, size_t n);

	// FT_MEM
	//=======================================
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

	//FT_PUT
	//=======================================
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_putnbr_base(int n, char *base);
char	*ft_putunbr_base(unsigned long int n, char *base);

	//FT_TO
	//=======================================
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

	//FT_INT
	//=======================================
size_t	ft_intlen(long int n);
size_t	ft_intlen_base(int n, int base);
size_t	ft_uintlen_base(unsigned long int n, size_t base);

	//FT_ALLOC
	//=======================================
void	*ft_calloc(size_t nmemb, size_t size);

	//LST_STRUCT
	//=======================================

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

	//FT_LST
	//=======================================
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

	//FT_PRINTF
	//=======================================
int		ft_printf(const char *format, ...);

#endif
