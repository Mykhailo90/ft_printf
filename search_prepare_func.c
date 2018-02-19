/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_prepare_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:33:35 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/19 20:33:36 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*search_sp_d(va_list argptr, t_list *com)
{
	char			*res_str;

	res_str = NULL;
	if (com->size == NULL)
		res_str = ft_itoa(va_arg(argptr, int));
	else if (input_symb(com->size, 'z'))
		res_str = ft_itoa((size_t)va_arg(argptr, size_t));
	else if (input_symb(com->size, 't'))
		res_str = ft_itoa((ptrdiff_t)va_arg(argptr, ptrdiff_t));
	else if (input_symb(com->size, 'j'))
		res_str = ft_itoa((intmax_t)va_arg(argptr, intmax_t));
	else if (input_symb(com->size, '2'))
		res_str = ft_itoa((long long)va_arg(argptr, long long));
	else if (input_symb(com->size, 'l'))
		res_str = ft_itoa((long)va_arg(argptr, long));
	else if (input_symb(com->size, 'h'))
		res_str = ft_itoa((short)va_arg(argptr, int));
	else if (input_symb(com->size, '1'))
		res_str = ft_itoa((signed char)va_arg(argptr, int));
	return (prepare_str(com, res_str));
}

char				*prepare_str_c(t_list *com, char *str)
{
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > ft_strlen(str)))
		str = add_esp_for_c(str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		!input_symb(com->flags, '-') &&
		ft_atoi(com->width) > ft_strlen(str))
		str = add_null_in_c(str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > ft_strlen(str)))
		str = add_esp_for_c_end(str, com);
	return (str);
}

unsigned char		*search_sp_c(va_list argptr, t_list *com, char s)
{
	char			*res_str;
	unsigned char	*str;
	wchar_t			ch[2];

	str = NULL;
	res_str = NULL;
	if (com->size == NULL && s != 'C')
	{
		res_str = ft_strnew(1);
		res_str[0] = va_arg(argptr, int);
	}
	else if (s == 'C' || input_symb(com->size, 'l'))
	{
		ch[0] = va_arg(argptr, wint_t);
		ch[1] = '\0';
		str = convert_in_str(ch);
		return (prepare_str_C(com, str));
	}
	return ((unsigned char *)prepare_str_c(com, res_str));
}

char				*prepare_str_ex(t_list *com)
{
	char			*res_str;

	res_str = ft_strnew(1);
	res_str[0] = '%';
	if (com->width && ft_atoi(com->width) > 1)
		res_str = add_esp(res_str, com);
	return (res_str);
}

char				*prepare_str_s(t_list *com, char *res_str)
{
	char			*res;
	int				len;

	if (com->precision)
		len = ft_atoi(com->precision);
	res = NULL;
	if (com->precision && len < ft_strlen(res_str))
	{
		res = ft_strnew(len);
		ft_strncpy(res, res_str, len);
		res_str = res;
	}
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > ft_strlen(res_str)))
		res_str = add_esp_for_c(res_str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		!input_symb(com->flags, '-') &&
		ft_atoi(com->width) > ft_strlen(res_str))
		res_str = add_null_in_c(res_str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > ft_strlen(res_str)))
		res_str = add_esp_for_c_end(res_str, com);
	return (res_str);
}
