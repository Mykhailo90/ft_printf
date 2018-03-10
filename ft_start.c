/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:17:25 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/09 20:17:26 by msarapii         ###   ########.fr       */
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

void				read_com_str(t_list *com, char *str)
{
	set_list_null(com);
	search_specificator(com, str);
	search_flags(com, str);
	search_width(com, str);
	search_pr(com, str);
	search_size(com, str);
}

int					go_print(char *str, t_list *com, va_list argptr,
								struct s_help *res)
{
	while (str[res->i] != '\0')
	{
		if (str[res->i] == '%')
		{
			if (!(str[(res->i = (res->i + 1))]))
				return (0);
			read_com_str(com, &str[res->i]);
			res->n += form_string(argptr, com, &str[res->i]);
			if (com->error == 5)
				while (str[res->i] != '%' && str[res->i] != '\0')
					res->i = res->i + 1;
			else if (com->error == 6)
				return (-1);
			else
				while (is_input_spec(str[++(res->i) - 1]) == -1)
					;
			set_list_null(com);
		}
		if (str[res->i] != '\0' && str[res->i] != '%')
		{
			ft_putchar(str[((res->i)++)]);
			res->n = res->n + 1;
		}
	}
	return (res->n);
}

int					ft_printf(char *str, ...)
{
	va_list			argptr;
	t_list			com;
	struct s_help	res;

	res.i = 0;
	res.n = 0;
	va_start(argptr, str);
	res.n = go_print(str, &com, argptr, &res);
	va_end(argptr);
	return (res.n);
}
