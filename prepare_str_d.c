/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_str_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:06:05 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/13 13:06:10 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		full_n(char *tmp, int i, int n)
{
	while (i < n)
	{
		tmp[i] = '0';
		i++;
	}
}

void		help_func(char *str, t_help *help, t_list *com)
{
	help->n = (com->precision) ? help->n - help->i + 1 : help->n - help->i;
	help->tmp[0] = (ft_atoi(str) < 0) ? '-' : '+';
	if (str[0] == '+' || str[0] == '-')
		str[0] = '0';
	help->i = 1;
}

char		*add_null_before(t_list *com, char *str)
{
	t_help	help;

	help.number = ft_atoi(str);
	help.i = ft_strlen(str);
	if (com->width)
		help.n = ft_atoi(com->width);
	help.tmp = (help.number < 0 || input_symb(com->flags, '+')) ?
		ft_strnew(help.n - help.i + 2) : ft_strnew(help.n - help.i);
	if (help.number < 0 || input_symb(com->flags, '+'))
		help_func(str, &help, com);
	else
	{
		help.n = help.n - help.i;
		help.i = 0;
	}
	full_n(help.tmp, help.i, help.n);
	str = ft_strjoin(help.tmp, str);
	free(help.tmp);
	return (str);
}

char		*add_esp(char *str, t_list *com)
{
	int		len_numb;
	int		width;
	char	*tmp;
	int		i;

	i = 0;
	len_numb = ft_strlen(str);
	width = ft_atoi(com->width);
	tmp = ft_strnew(width - len_numb);
	while (i < (width - len_numb))
		tmp[i++] = ' ';
	str = (input_symb(com->flags, '-')) ?
		ft_strjoin(str, tmp) : ft_strjoin(tmp, str);
	free(tmp);
	return (str);
}

char		*prepare_str(t_list *com, char *str)
{
	if (!com->precision && com->width &&
		ft_atoi(com->width) > (int)ft_strlen(str) &&
		input_symb(com->flags, '0') && !input_symb(com->flags, '-'))
		str = add_null_before(com, str);
	if (com->precision && ft_atoi(com->precision) > (int)ft_strlen(str))
		str = add_null(com, str);
	if (com->precision && com->width && ft_atoi(com->width) >
		(int)ft_strlen(str) && !input_symb(com->flags, '-'))
		str = add_esp(str, com);
	if (input_symb(com->flags, '+') && (ft_atoi(str) >= 0) &&
		!input_symb(str, '+') && !input_symb(com->flags, '-'))
		str = ft_strjoin("+", str);
	if (input_symb(com->flags, '+') && (ft_atoi(str) >= 0) &&
		str[0] != '+' && input_symb(com->flags, '-'))
		str = ft_strjoin("+", str);
	if (input_symb(com->flags, ' ') && (ft_atoi(str) >= 0) &&
		!input_symb(com->flags, '+'))
		str = ft_strjoin(" ", str);
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	if (com->width && input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	return (str);
}
