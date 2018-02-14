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

static void search_last_pos(t_list *com, char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (com->width)
		ft_strdel(&com->width);
	com->width = ft_strnew(i);
	com->width = ft_strncpy(com->width, &str[0], i);
}

void search_width(t_list *com, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (ft_isdigit(str[i]) && i == 0)
			search_last_pos(com, &str[i]);
		else if (ft_isdigit(str[i]) && str[i] != '0' && str[i - 1] != '.'
			&& (!ft_isdigit(str[i - 1]) || str[i - 1] == '0'))
			search_last_pos(com, &str[i]);
		i++;
	}
}