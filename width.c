/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:50:52 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/08 18:50:54 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void search_last_pos(t_list *commands, char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (commands->width)
		ft_strdel(&commands->width);
	commands->width = ft_strnew(i);
	commands->width = ft_strncpy(commands->width, &str[0], i);
}

void search_width(t_list *commands, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (ft_isdigit(str[i]) && str[i] != '0' && str[i - 1] != '.' &&
			((str[i - 1] == '0' && !ft_isdigit(str[i - 2])) ||
				is_it_flags(str[i - 1]) || is_it_size(str[i - 1])))
			search_last_pos(commands, &str[i]);
		i++;
	}
}