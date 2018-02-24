/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prepare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:56:37 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 11:56:38 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*prepare_str_x(t_list *com, char *str, char ch)
{
	if (com->precision && ft_atoi(com->precision) == 0 && !input_symb(com->flags, '#'))
	{
		str = add_hesh(com, str, ch);
	}
	if (!com->precision && com->width &&
		ft_atoi(com->width) > (int)ft_strlen(str) &&
		input_symb(com->flags, '0') && !input_symb(com->flags, '-'))
		str = add_null_before_xv(com, str, ch);
	if (input_symb(com->flags, '#') && (ch == 'o' || ch == 'O'))
		str = add_hesh_o(str);
	if (com->precision && ft_atoi(com->precision) > (int)ft_strlen(str))
		str = add_null(com, str);
	if (input_symb(com->flags, '#') && (ch == 'x' || ch == 'X') &&
		(str[0] != '0' || str[1] != '\0'))
	{
		str = add_hesh(com, str, ch);
	}
	if (ch == 'p')
		str = add_hesh(com, str, ch);
	if (com->precision && com->width &&
		ft_atoi(com->width) > (int)ft_strlen(str)
		&& !input_symb(com->flags, '-'))
		str = add_esp(str, com);
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	if (com->width && input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	return (str);
}

unsigned char			*prepare_str_sv(t_list *com, unsigned char *res_str)
{
	unsigned char		*res;
	int					len;

	if (com->precision)
		len = ft_atoi(com->precision);
	res = NULL;
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen_uv(res_str)))
		res_str = add_esp_for_cv(res_str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		!input_symb(com->flags, '-') &&
		ft_atoi(com->width) > (int)ft_strlen_uv(res_str))
		res_str = add_null_in_cv(res_str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen_uv(res_str)))
		res_str = add_esp_for_cv_end(res_str, com);
	return (res_str);
}

unsigned char			*add_esp_for_cv_end(unsigned char *str, t_list *com)
{
	int					len_ch;
	int					width;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = ft_strlen_uv(str);
	width = ft_atoi(com->width);
	tmp = ft_strnew(width - len_ch);
	while (i < (width - len_ch))
		tmp[i++] = ' ';
	str = ft_strjoin_uv(str, (unsigned char *)tmp);
	free(tmp);
	return (str);
}

unsigned char			*prepare_str_cv(t_list *com, unsigned char *str)
{
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen_uv(str)))
		str = add_esp_for_cv(str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		!input_symb(com->flags, '-') &&
		ft_atoi(com->width) > (int)ft_strlen_uv(str))
		str = add_null_in_cv(str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen_uv(str)))
		str = add_esp_for_cv_end(str, com);
	return (str);
}

char					*add_esp_for_c(char *str, t_list *com)
{
	int					len_ch;
	int					width;
	char				*tmp;
	int					i;
	int 				flag;

	i = 0;
	len_ch = ft_strlen(str);
	if (str[0] == 0)
		len_ch = 1;
	width = ft_atoi(com->width);
	flag = width - len_ch;
	tmp = (com->precision && ft_atoi(com->precision) == 0) ?
	ft_strnew(width - len_ch + 1) : ft_strnew(width - len_ch);
	if (com->precision && ft_atoi(com->precision) == 0)
		flag++;
	while (i < flag)
		tmp[i++] = ' ';
	str = (input_symb(com->flags, '-')) ?
		ft_strjoin(str, tmp) : ft_strjoin(tmp, str);
	free(tmp);
	return (str);
}
