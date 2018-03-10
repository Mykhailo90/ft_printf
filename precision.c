/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:58:17 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/08 19:58:18 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_pr(t_list *commands, char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (commands->pr)
		ft_strdel(&commands->pr);
	commands->pr = ft_memalloc(sizeof(char) * i + 1);
	commands->pr = ft_strncpy(commands->pr, &str[0], i);
}

void	search_pr(t_list *commands, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (str[i] == '.')
		{
			if (commands->pr)
				ft_strdel(&commands->pr);
			commands->pr = ft_memalloc(sizeof(char) * 2);
			commands->pr[0] = '0';
			commands->pr[1] = '\0';
		}
		if (str[i] == '.' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
			write_pr(commands, &str[i + 1]);
		i++;
	}
}
