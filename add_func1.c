/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:35:34 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 11:35:35 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*add_hesh(char *res, char ch)
{
	char		*for_del;
	char		tmp[3];

	for_del = res;
	tmp[0] = '0';
	tmp[2] = '\0';
	tmp[1] = (ch == 'x' || ch == 'p') ? 'x' : 'X';
	if (ch == 'p' && res[0] == '0' && res[1] == '\0'){
		free(for_del);
		return ("0x");
	}
	res = ft_strjoin(tmp, res);
	free(for_del);
	return (res);
}

char			*add_null_xv(t_list *com, char *str)
{
	t_help		help;

	help.i = ft_strlen(str);
	if (input_symb(com->flags, '#'))
		help.i = help.i + 2;
	if (com->precision)
		help.n = ft_atoi(com->precision);
	help.tmp = ft_strnew(help.n - help.i);
	help.n = help.n - help.i;
	help.i = 0;
	full_n(help.tmp, help.i, help.n);
	str = ft_strjoin(help.tmp, str);
	free(help.tmp);
	return (str);
}

char			*add_null_before_xv(t_list *com, char *str, char ch)
{
	t_help		help;

	help.number = ft_atoi(str);
	help.i = ft_strlen(str);
	if (input_symb(com->flags, '#') && (ch == 'x' || ch == 'X'))
		help.i = help.i + 2;
	if (input_symb(com->flags, '#') && (ch == 'o' || ch == 'O'))
		help.i = help.i + 1;
	if (ch == 'p')
		help.i = help.i + 2;
	if (com->width)
		help.n = ft_atoi(com->width);
	help.tmp = (help.number < 0 || input_symb(com->flags, '+')) ?
		ft_strnew(help.n - help.i + 2) : ft_strnew(help.n - help.i);
	help.n = help.n - help.i;
	help.i = 0;
	full_n(help.tmp, help.i, help.n);
	str = ft_strjoin(help.tmp, str);
	free(help.tmp);
	return (str);
}

unsigned char	*add_null_in_cv(unsigned char *str, t_list *com)
{
	int			len_ch;
	int			w;
	char		*tmp;
	int			i;

	i = 0;
	len_ch = ft_strlen_uv(str);
	w = ft_atoi(com->width);
	tmp = ft_strnew(w - len_ch);
	while (i < (w - len_ch))
		tmp[i++] = '0';
	str = ft_strjoin_uv((unsigned char *)tmp, str);
	free(tmp);
	return (str);
}

unsigned char	*add_esp_for_cv(unsigned char *str, t_list *com)
{
	int			len_ch;
	int			width;
	char		*tmp;
	int			i;

	i = 0;
	len_ch = ft_strlen((char *)str);
	width = ft_atoi(com->width);
	tmp = ft_strnew(width - len_ch);
	while (i < (width - len_ch))
		tmp[i++] = ' ';
	str = (input_symb(com->flags, '-')) ?
		ft_strjoin_uv(str, (unsigned char *)tmp) :
		ft_strjoin_uv((unsigned char *)tmp, str);
	free(tmp);
	return (str);
}
