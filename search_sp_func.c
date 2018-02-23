/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sp_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:10:02 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 11:10:03 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*search_sp_dv(va_list argptr, t_list *com, char ch)
{
	char *res_str;

	res_str = NULL;
	if (ch == 'U')
		res_str = ft_itoa_u(va_arg(argptr, unsigned long long));
	else if (com->size == NULL){
		res_str = ft_itoa(va_arg(argptr, long));
	}
	else if (input_symb(com->size, 'z'))
		res_str = ft_itoa((size_t)va_arg(argptr, size_t));
	else if (input_symb(com->size, 't'))
		res_str = ft_itoa((ptrdiff_t)va_arg(argptr, ptrdiff_t));
	else if (input_symb(com->size, 'j'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned int));
	else if (input_symb(com->size, '2'))
		res_str = ft_itoa((long long)va_arg(argptr, long long));
	else if (input_symb(com->size, 'l'))
		res_str = ft_itoa((long)va_arg(argptr, long));
	else if (input_symb(com->size, 'h'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned int));
	 else if (input_symb(com->size, '1'))
	 	res_str = ft_itoa_u(va_arg(argptr, unsigned int));
	return (prepare_str(com, res_str));
}

char				*search_sp_uv(va_list argptr, t_list *com)
{
	char			*res_str;

	res_str = NULL;
	if (com->size == NULL)
		res_str = ft_itoa(va_arg(argptr, unsigned long));
	else if (input_symb(com->size, 'z'))
		res_str = ft_itoa((size_t)va_arg(argptr, size_t));
	else if (input_symb(com->size, 't'))
		res_str = ft_itoa(va_arg(argptr, ptrdiff_t));
	else if (input_symb(com->size, '2'))
		res_str = ft_itoa(va_arg(argptr, unsigned long long));
	else if (input_symb(com->size, 'l'))
		res_str = ft_itoa(va_arg(argptr, unsigned long));
	return (prepare_str(com, res_str));
}

unsigned char		*search_sp_s(va_list argptr, t_list *com, char ch)
{
	char			*res_str;
	unsigned char	*res;

	res_str = NULL;
	res = NULL;
	if (com->size == NULL && ch != 'S')
		res_str = va_arg(argptr, char *);
	else if (ch == 'S' || (com->size && input_symb(com->size, 'l')))
	{
		res = search_wt_str(argptr, com);
		return (prepare_str_sv(com, res));
	}
	return ((unsigned char *)prepare_str_s(com, res_str));
}

unsigned char		*search_sp_x(va_list argptr, t_list *com, char ch)
{
	char			*res_str;
	unsigned long long n;

	res_str = NULL;
	n = va_arg(argptr, unsigned long long);
	if (ch == 'O')
		res_str = ft_itoa_base(n, ch);
	else if (com->size == NULL)
		res_str = ft_itoa_base((unsigned int)n, ch);
	else if (input_symb(com->size, 'z'))
		res_str = ft_itoa_base((size_t)n, ch);
	else if (input_symb(com->size, 't'))
		res_str = ft_itoa_base((ptrdiff_t)n, ch);
	else if (input_symb(com->size, 'j'))
		res_str = ft_itoa_base((uintmax_t)n, ch);
	else if (input_symb(com->size, '2'))
		res_str = ft_itoa_base(n, ch);
	else if (input_symb(com->size, 'l'))
		res_str = ft_itoa_base(n, ch);
	else if (input_symb(com->size, 'h'))
		res_str = ft_itoa_base((unsigned short int)n, ch);
	else if (input_symb(com->size, '1'))
		res_str = ft_itoa_base((unsigned char)n, ch);
	return ((unsigned char *)prepare_str_x(com, res_str, ch));
}

char		*prepare_str_u(t_list *com, char *str)
{
	if (com->precision && ft_atoi(com->precision) == 0)
	{
		free(str);
		return ("\0");
	}
	if (!com->precision && com->width &&
		ft_atoi(com->width) > (int)ft_strlen(str) &&
		input_symb(com->flags, '0') && !input_symb(com->flags, '-'))
		str = add_null_before(com, str);
	if (com->precision && ft_atoi(com->precision) > (int)ft_strlen(str))
		str = add_null(com, str);
	if (com->precision && com->width && ft_atoi(com->width) >
		(int)ft_strlen(str) && !input_symb(com->flags, '-'))
		str = add_esp(str, com);
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	if (com->width && input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	return (str);
}

char				*search_sp_u(va_list argptr, t_list *com)
{
	char			*res_str;

	res_str = NULL;
	if (com->size == NULL)
		res_str = ft_itoa(va_arg(argptr, unsigned int));
	else if (input_symb(com->size, 'z'))
		res_str = ft_itoa_u(va_arg(argptr, size_t));
	else if (input_symb(com->size, 't'))
		res_str = ft_itoa((unsigned long long)va_arg(argptr, ptrdiff_t));
	else if (input_symb(com->size, 'j'))
		res_str = ft_itoa_u((intmax_t)va_arg(argptr, uintmax_t));
	else if (input_symb(com->size, '2'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned long long));
	else if (input_symb(com->size, 'l'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned long));
	else if (input_symb(com->size, 'h'))
		res_str = ft_itoa((unsigned short)va_arg(argptr, int));
	else if (input_symb(com->size, '1'))
		res_str = ft_itoa((unsigned char)va_arg(argptr, int));
	return (prepare_str_u(com, res_str));
}
