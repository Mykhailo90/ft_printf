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
		res_str = ft_itoa(va_arg(argptr, unsigned long));
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
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp_for_c(str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		!input_symb(com->flags, '-') &&
		ft_atoi(com->width) > (int)ft_strlen(str))
		str = add_null_in_c(str, com);
	else if (com->width && input_symb(com->flags, '0') &&
		input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp_for_c_end(str, com);
	return (str);
}

unsigned char		*search_sp_c(long n, t_list *com, char s)
{
	char			*res_str;
	unsigned char	*str;
	wchar_t			ch[2];

	str = NULL;
	res_str = NULL;
	if (com->size == NULL && s != 'C')
	{
		res_str = ft_strnew(1);
		res_str[0] = (n != 0) ? (char)n : '\0';
	}
	else if (s == 'C' || input_symb(com->size, 'l'))
	{
		if (n == 0)
			write(1, "\0", 1);
		ch[0] = n;
		ch[1] = '\0';
		str = convert_in_str(ch);
		return (prepare_str_cv(com, str));
	}
	return ((unsigned char *)prepare_str_c(com, res_str));
}

char				*prepare_str_ex(t_list *com)
{
	char			*res_str;

	res_str = ft_strnew(1);
	res_str[0] = '%';
	if (com->width && ft_atoi(com->width) > 1 && !input_symb(com->flags, '0'))
		res_str = add_esp(res_str, com);
	if (com->width && ft_atoi(com->width) > 1 && input_symb(com->flags, '0'))
		res_str = add_null_in_s(res_str, com);
	return (res_str);
}

char 				*add_null_in_s(char *res_str, t_list *com)
{
	int			len_ch;
	int			w;
	char		*tmp;
	int			i;
	char		*del;

	i = 0;
	del = res_str;
	len_ch = (int)ft_strlen(res_str);
	w = ft_atoi(com->width);
	i = (!res_str) ? w : (w - len_ch);
	tmp = ft_strnew(i);
	w = 0;
	while (w < i)
		tmp[w++] = '0';
	res_str = ft_strjoin(tmp, res_str);
	free(tmp);
	return (res_str);
}

char				*prepare_str_s(t_list *com, char *res_str)
{
	char			*res;
	char			*nn = "(null)";
	char			n[] = "\0";

	if (res_str == NULL && com->pr && ft_atoi(com->pr) == 0)
	{
		res_str = n;
	}
	else if (res_str == NULL)
	{
		res_str = nn;
	}
	if (com->pr && ft_atoi(com->pr) < (int)ft_strlen(res_str))
	{
		res = ft_strnew(ft_atoi(com->pr));
		ft_strncpy(res, res_str, ft_atoi(com->pr));
		res_str = res;
	}
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen(res_str)))
	{
		res_str = add_esp_for_c(res_str, com);
	}
	else if (com->width && input_symb(com->flags, '0') &&
		!input_symb(com->flags, '-') &&
		ft_atoi(com->width) > (int)ft_strlen(res_str))
	{
		res_str = add_null_in_s(res_str, com);
	}
	else if (com->width && input_symb(com->flags, '0') &&
		input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen(res_str)))
	{
		res_str = add_esp_for_c_end(res_str, com);
	}
	return (res_str);
}

unsigned char		*search_sp_s(va_list argptr, t_list *com, char ch)
{
	char			*res_str;
	unsigned char	*res;

	res_str = NULL;
	res = NULL;
	if (com->size == NULL && ch != 'S')
	{
		res_str = va_arg(argptr, char *);
	}
	else if (ch == 'S' || (com->size && input_symb(com->size, 'l')))
	{
		res = search_wt_str(argptr, com);
		return (prepare_str_sv(com, res));
	}
	return ((unsigned char *)prepare_str_s(com, res_str));
}









