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

struct s_form			*form_p1(va_list argptr, t_list *com,
							struct s_form *r)
{
	char				ch;
	unsigned long long	tp;

	ch = com->specificator;
	if (ch == 'd' || ch == 'i')
		r->res = (unsigned char *)search_sp_d(argptr, com);
	else if (ch == 'D' || ch == 'U')
		r->res = (unsigned char *)search_sp_dv(argptr, com, ch);
	else if (ch == '%')
		r->res = (unsigned char *)prepare_str_ex(com);
	else if (ch == 's' || ch == 'S')
		r->res = search_sp_s(argptr, com, ch);
	else if (ch == 'u')
		r->res = (unsigned char *)search_sp_u(argptr, com);
	else if (ch == 'p')
	{
		tp = (unsigned long long)va_arg(argptr, unsigned long int);
		r->res = (unsigned char *)search_sp_p(tp, com, ch);
	}
	return (r);
}

struct s_form			*form_p2(va_list argptr, t_list *com,
							struct s_form *r)
{
	char				ch;

	ch = com->specificator;
	if ((ch == 'C') && MB_CUR_MAX == 1)
	{
		com->error = 6;
		r->len = -1;
	}
	else if (ch == 'c' || ch == 'C')
	{
		r->tmp = (ch == 'c') ? (long)va_arg(argptr, int) :
							(long)va_arg(argptr, wint_t);
		r->res = (unsigned char *)search_sp_c(r->tmp, com, ch);
		if (r->tmp == 0 && !com->width)
		{
			write(1, "\0", 1);
			ft_putstr(r->res);
			r->len = -2;
		}
	}
	return (r);
}

struct s_form			*form_p3(va_list argptr, t_list *com,
							struct s_form *r)
{
	char				ch;
	unsigned long long	tp;

	ch = com->specificator;
	if (ch == 'x' || ch == 'X' || ch == 'O' || ch == 'o')
	{
		tp = va_arg(argptr, unsigned long long);
		r->res = (unsigned char *)search_sp_x(tp, com, ch);
		if (tp == 0 && com->pr && !com->width &&
			ft_atoi(com->pr) == 0 && !input_symb(com->flags, '#'))
			r->len = -3;
		else if (tp == 0 && com->pr && com->width &&
			ft_atoi(com->pr) == 0 && !input_symb(com->flags, '#'))
			r->res = (unsigned char *)prepare_str_s(com, "0");
		if (ch == 'x' && tp == 0 && com->pr &&
			ft_atoi(com->pr) == 0 && !com->width)
			r->len = -3;
	}
	return (r);
}

struct s_form			*form_p4(t_list *com,
							struct s_form *r)
{
	char				ch;

	ch = com->specificator;
	if (com->error != 6 && ch == 'c' && r->tmp == 0 && com->width)
	{
		ft_putstr(r->res);
		write(1, "\0", 1);
		r->len += 1;
	}
	else if (com->error != 6)
		ft_putstr(r->res);
	return (r);
}

int						form_string(va_list argptr, t_list *com, char *str)
{
	char				ch;
	struct s_form		*r;

	r = ft_memalloc(sizeof(struct s_form));
	r->res = NULL;
	r->res = (unsigned char *)search_errors(com, str);
	ch = com->specificator;
	if (r->res)
		;
	else if (!r->res)
		r = form_p1(argptr, com, r);
	r = form_p2(argptr, com, r);
	if (r->len == -1)
		return (-1);
	if (r->len == -2)
		return (1);
	if (!r->res)
	{
		r = form_p3(argptr, com, r);
		if (r->len == -3)
			return (0);
	}
	r->len = (int)ft_strlen_uv(r->res);
	r = form_p4(com, r);
	return (r->len);
}
