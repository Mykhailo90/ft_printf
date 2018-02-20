/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:48:42 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 13:49:03 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					search_errors(t_list *com, char *str)
{
	int				i;
	char			arg[] = "sSpdDioOuUxXcClhLjzt0123456789. \0";
	i = 0;
	while (str[i] != com->specificator && str[i] != '\0')
	{
		if (!input_symb(arg, str[i]))
		{
			i = 0;
			while (str[i - 1] != com->specificator && str[i] != '\0')
				ft_putchar(str[i++]);
			return (i);
		}
		i++;
		if (str[i] == '\0')
		{
			ft_putstr((unsigned char const *)str);
			return (i);
		}
	}
	return (0);
}

int					form_string(va_list argptr, t_list *com, char *str)
{
	char			ch;
	unsigned char	*res;
	int				len;

	res = NULL;
	len = search_errors(com, str);
	ch = com->specificator;
	if (len)
		return (len);
	else if (ch == 'd' || ch == 'i')
		res = (unsigned char *)search_sp_d(argptr, com);
	else if (ch == 'D' || ch == 'U')
		res = (unsigned char *)search_sp_dv(argptr, com);
	else if (ch == 'c' || ch == 'C')
		res = (unsigned char *)search_sp_c(argptr, com, ch);
	else if (ch == '%')
		res = (unsigned char *)prepare_str_ex(com);
	else if (ch == 's' || ch == 'S')
	{
		res = (unsigned char *)search_sp_s(argptr, com, ch);
	}
	else if (ch == 'x' || ch == 'X' || ch == 'O' || ch == 'o')
		res = (unsigned char *)search_sp_x(argptr, com, ch);
	else if (ch == 'u')
		res = (unsigned char *)search_sp_u(argptr, com);
	else if (ch == 'p')
		res = (unsigned char *)search_sp_p(argptr, com, ch);
	len = (int)ft_strlen_uv(res);
	ft_putstr(res);
	return (len);
}

void				read_com_str(t_list *com, char *str)
{
	set_list_null(com);
	search_specificator(com, str);
	search_flags(com, str);
	search_width(com, str);
	search_precision(com, str);
	search_size(com, str);
}

int					ft_printf(char *str, ...)
{
	va_list			argptr;
	t_list			com;
	int				i;
	int				res;

	i = 0;
	res = 0;
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			read_com_str(&com, &str[++i]);
			res += form_string(argptr, &com, &str[i]);
			set_list_null(&com);
			while (is_input_spec(str[++i - 1]) == -1)
				;
		}
		if (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
			res++;
		}		
	}
	va_end(argptr);
	return (res);
}
