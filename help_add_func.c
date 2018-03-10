/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_add_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:07:31 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/19 20:07:32 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_list_null(t_list *com)
{
	com->size = NULL;
	com->pr = NULL;
	com->width = NULL;
	com->flags = NULL;
}

char		*add_null(t_list *com, char *str)
{
	t_help	help;

	help.number = ft_atoi(str);
	help.i = ft_strlen(str);
	if (com->pr)
		help.n = ft_atoi(com->pr);
	help.tmp = (help.number < 0 || input_symb(com->flags, '+')) ?
		ft_strnew(help.n - help.i + 1) : ft_strnew(help.n - help.i);
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

char		*add_esp_for_c_end(char *str, t_list *com)
{
	int		len_ch;
	int		width;
	char	*tmp;
	int		i;

	i = 0;
	len_ch = ft_strlen(str);
	width = ft_atoi(com->width);
	tmp = ft_strnew(width - len_ch);
	while (i < (width - len_ch))
		tmp[i++] = ' ';
	str = ft_strjoin(str, tmp);
	free(tmp);
	return (str);
}

char		*add_null_in_c(char *str, t_list *com)
{
	int		len_ch;
	int		w;
	char	*tmp;
	int		i;

	i = 0;
	len_ch = ft_strlen(str);
	if (str[0] == 0)
		len_ch = 1;
	w = ft_atoi(com->width);
	tmp = ft_strnew(w - len_ch);
	while (i < (w - len_ch))
		tmp[i++] = '0';
	str = ft_strjoin(tmp, str);
	free(tmp);
	return (str);
}

char		*add_hesh_o(char *res)
{
	char	*for_del;
	char	tmp[2];

	for_del = res;
	tmp[0] = '0';
	tmp[1] = '\0';
	if (res[0] != '0')
		res = ft_strjoin(tmp, res);
	free(for_del);
	return (res);
}
