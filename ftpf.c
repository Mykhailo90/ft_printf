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

char				*prep_part2(char *str, int *i)
{
	char			*res;
	int				n;

	n = *i;
	while (str[*i] != '%' && str[*i] != '\0')
		*i = *i + 1;
	res = ft_strnew(*i - n);
	res = ft_strncpy(res, &str[n], (*i - n));
	return (res);
}

char				*search_errors(t_list *com, char *str)
{
	int				i;
	int 			tmp;
	char			arg[] = "+-#sSpdDioOuUxXcClhLjzt0123456789. \0";
	char			*res_str;
	char			*fdel;

	res_str = NULL;
	i = 0;
	while (str[i] != com->specificator && str[i] != '\0')
	{
		if (!input_symb(arg, str[i]))
		{
			i = 0;
			while (input_symb(arg, str[i]))
				i++;
			tmp = i;
			res_str = ft_strnew(1);
			res_str[0] = str[i++];
			res_str = prepare_str_s(com, res_str);
			fdel = prep_part2(str, &i);
			res_str = ft_strjoin(res_str, fdel);
			free(fdel);
		}
		else if (str[i] == '\0')
		{
			res_str = ft_strnew(i);
			res_str = ft_strcpy(res_str, str);
			ft_putstr((unsigned char const *)str);
			return (res_str);
		}
		if (str[i] != '\0')
			i++;		
	}
	if (res_str)
		com->error = 5; 
	return (res_str);
}

int					form_string(va_list argptr, t_list *com, char *str)
{
	char			ch;
	unsigned char	*res;
	int				len;
	long			tmp;

	res = NULL;
	res = (unsigned char *)search_errors(com, str);
	ch = com->specificator;
	if (res)
		;
	else if (ch == 'd' || ch == 'i')
		res = (unsigned char *)search_sp_d(argptr, com);
	else if (ch == 'D' || ch == 'U')
		res = (unsigned char *)search_sp_dv(argptr, com, ch);
	else if ((ch == 'c' || ch == 'C') && MB_CUR_MAX != 1)
	{
		tmp = (ch == 'c') ? (long)va_arg(argptr, int) :
							(long)va_arg(argptr, wint_t);
		res = (unsigned char *)search_sp_c(tmp, com, ch);
		if (tmp == 0 && !com->width)
		{
			write(1, "\0", 1);
			ft_putstr(res);
			return (1);
		}
	}
	else if ((ch == 'c' || ch == 'C') && MB_CUR_MAX == 1)
    {
    	com->error = 6;
    	return (-1);
    }
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
	{
		res = (unsigned char *)search_sp_p(argptr, com, ch);
	}
	len = (int)ft_strlen_uv(res);
	if (com->error != 6 && ch == 'c' && tmp == 0 && com->width)
	{	
		ft_putstr(res);
		write(1, "\0", 1);
		len += 1;
	}
	else if (com->error != 6)
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
			if (!(str[++i]))
				return (0);
			read_com_str(&com, &str[i]);
			res += form_string(argptr, &com, &str[i]);
			if (com.error == 5)
			{
				while (str[i] != '%' && str[i] != '\0')
				i++;
			}
			else if (com.error == 6)
				return (-1);
			else
				while (is_input_spec(str[++i - 1]) == -1)
				;
			set_list_null(&com);
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
			res++;
		}
	}
	va_end(argptr);
	return (res);
}
