/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:58:17 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/08 19:58:18 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void write_precision(t_list *commands, char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (commands->precision)
		ft_strdel(&commands->width);
	commands->precision = ft_memalloc(sizeof(char) * i + 1);
	commands->precision = ft_strncpy(commands->precision, &str[0], i);
}

void search_precision(t_list *commands, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (str[i] == '.')
		{
			if (commands->precision)
				ft_strdel(&commands->width);
			commands->precision = ft_memalloc(sizeof(char) * 2);
			commands->precision[0] = '0';
			commands->precision[1] = '\0';
		}
		if (str[i] == '.' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
			write_precision(commands, &str[i + 1]);
		i++;
	}
}
