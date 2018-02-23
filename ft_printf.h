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
# include <inttypes.h>
# include <stddef.h>
# include <wchar.h>

typedef struct		s_list
{
	int				error;
	char			*flags;
	char			*width;
	char			*precision;
	char			*size;
	char			specificator;
}					t_list;

typedef struct		s_help
{
	int				i;
	int				n;
	char			*tmp;
	int				number;
}					t_help;

unsigned char		*ft_strcat_uv(unsigned char *dest,
					const unsigned char *src);
size_t				ft_strlen_uv(const unsigned char *s);
unsigned char		*ft_strncpy_uv(unsigned char *dest,
					const unsigned char *src, size_t n);
unsigned char		*ft_strjoin_uv(unsigned char const *s1,
					unsigned char const *s2);
unsigned char		*ft_strcpy_uv(unsigned char *dest,
					const unsigned char *src);
void				ft_putchar(unsigned char c);
char				*add_esp(char *str, t_list *com);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
int					is_it_size(char ch);
int					is_it_flags(char ch);
int					search_fl_n(char *str);
int					search_dif_fl(char *str, char x);
void				search_flags(t_list *commands, char *str);
void				search_specificator(t_list *commands, char *str);
void				ft_putstr(unsigned char const *s);
void				ft_putnbr(int n);
int					is_input_spec(char ch);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memalloc(size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_itoa(long long n);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isdigit(int character);
int					ft_is_it_space(char ch);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
size_t				len_s(char *str);
void				search_width(t_list *com, char *str);
void				search_size(t_list *commands, char *str);
void				search_precision(t_list *commands, char *str);
void				write_precision(t_list *commands, char *str);
int					input_symb(char *str, char ch);
char				*prepare_str(t_list *com, char *str);
char				*add_null_before(t_list *com, char *str);
char				*add_null(t_list *com, char *str);
void				full_n(char *tmp, int i, int n);
void				help_func(char *str, t_help *help, t_list *com);
unsigned char		*convert_in_str1(wchar_t *tmp, int l);
unsigned char		*convert_in_str(wchar_t *tmp);
char				*prepare_str_s(t_list *com, char *res_str);
char				*add_hesh_o(char *res);
char				*search_sp_d(va_list argptr, t_list *com);
unsigned char		*search_sp_c(long n, t_list *com, char s);
char				*prepare_str_ex(t_list *com);
void				set_list_null(t_list *com);
int					size_wt(wchar_t *tmp);
char				*add_null_in_c(char *str, t_list *com);
char				*add_esp_for_c(char *str, t_list *com);
unsigned char		*add_esp_for_cv_end(unsigned char *str, t_list *com);
char				*add_esp_for_c_end(char *str, t_list *com);
unsigned char		*prepare_str_cv(t_list *com, unsigned char *str);
void				func_help1(wchar_t *tmp, unsigned char *res,
								int len);
char				*search_sp_dv(va_list argptr, t_list *com, char ch);
unsigned char		*search_sp_s(va_list argptr, t_list *com, char ch);
char				*search_sp_uv(va_list argptr, t_list *com);
unsigned char		*search_sp_x(va_list argptr, t_list *com, char ch);
char				*search_sp_u(va_list argptr, t_list *com);
unsigned char		*search_wt_str(va_list argptr, t_list *com);
char				*ft_itoa_base(unsigned long long number, char ch);
char				*prepare_str_x(t_list *com, char *str, char ch);
unsigned char		*prepare_str_sv(t_list *com, unsigned char *res_str);
char				*add_null_xv(t_list *com, char *str);
char				*add_null_before_xv(t_list *com, char *str, char ch);
char				*add_hesh(char *res, char ch);
unsigned char		*add_esp_for_cv(unsigned char *str, t_list *com);
unsigned char		*add_null_in_cv(unsigned char *str, t_list *com);
char				*search_sp_p(unsigned long int tmp, t_list *com, char ch);
int					form_string(va_list argptr, t_list *com, char *str);
void				read_com_str(t_list *com, char *str);
char				*search_errors(t_list *com, char *str);
int					ft_printf(char *str, ...);
int					ft_is_it_space(char ch);
char				*ft_itoa_u(unsigned long long n);
char				*prepare_str_u(t_list *com, char *str);
char				*prepare_str_p(t_list *com, char *str, char ch);
#endif
