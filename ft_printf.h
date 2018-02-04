/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:36:13 by msarapii          #+#    #+#             */
/*   Updated: 2018/01/30 16:36:17 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
#include <inttypes.h>
#include <stddef.h> 

typedef struct 	s_list
{
	char		*flags;
	char		*width;
	char		*precision;
	char		*size;
	char 		specificator;
}				t_list;
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putnbr(int n);
int			is_input_spec(char ch);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memalloc(size_t size);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_itoa(size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *nptr);
int 		ft_isdigit(int character);
int			ft_is_it_space(char ch);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strnew(size_t size);
#endif