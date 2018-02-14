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
#include <wchar.h>

typedef struct 	s_list
{
	char		*flags;
	char		*width;
	char		*precision;
	char		*size;
	char 		specificator;
}				t_list;

typedef struct 	s_help
{
	int 		i;
	int 		n;
	char 		*tmp;
	int 		number;
}				t_help;

void			ft_putchar(char c);
char			*add_esp(char *str, t_list *com);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
int 			is_it_size(char ch);
int 			is_it_flags(char ch);
int 			search_fl_n(char *str);
int 			search_dif_fl(char *str, char x);
void 			search_flags(t_list *commands, char *str);
void			search_specificator(t_list *commands, char *str);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
int				is_input_spec(char ch);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memalloc(size_t size);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_itoa(long long n);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);
int 			ft_isdigit(int character);
int				ft_is_it_space(char ch);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
size_t 			len_s(char *str);
void 			search_width(t_list *com, char *str);
void 			search_size(t_list *commands, char *str);
static void 	search_last_pos(t_list *com, char *str);
void 			search_precision(t_list *commands, char *str);
void 			write_precision(t_list *commands, char *str);
void			*ft_memchr(const void *s, int c, size_t n);
int				input_symb(char *str, char ch);
char			*prepare_str(t_list *com, char *str);

#endif