/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:17:48 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 12:18:06 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					input_symb(char *str, char ch)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char				*search_sp_p(va_list argptr, t_list *com, char ch)
{
	char			*res_str;

	res_str = NULL;
	res_str = ft_itoa_base(va_arg(argptr, unsigned long int), ch);
	return (prepare_str_x(com, res_str, ch));
}

int					size_wt(wchar_t *tmp)
{
	int				i;
	int				n;

	i = 0;
	n = 0;
	while (tmp[i])
	{
		if (tmp[i] <= 127)
			n += 1;
		else if (tmp[i] <= 2047)
			n += 2;
		else if (tmp[i] <= 65535)
			n += 3;
		else if (tmp[i] <= 1114111)
			n += 4;
		i++;
	}
	return (n);
}
