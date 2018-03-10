/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:57:02 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/10 13:57:03 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*help_search(char *res_str, t_list *com, char *str, int *n)
{
	char			*fdel;
	char			*arg;

	arg = "+-#sSpdDioOuUxXcClhLjzt0123456789. \0";
	*n = 0;
	while (input_symb(arg, str[*n]))
		*n = *n + 1;
	res_str = ft_strnew(1);
	res_str[0] = str[*n];
	*n = *n + 1;
	res_str = prepare_str_c(com, res_str);
	fdel = prep_part2(str, n);
	res_str = ft_strjoin(res_str, fdel);
	free(fdel);
	return (res_str);
}

char				*search_errors(t_list *com, char *str)
{
	int				i;
	char			*res_str;
	char			*arg;

	arg = "+-#sSpdDioOuUxXcClhLjzt0123456789. \0";
	res_str = NULL;
	i = 0;
	while (str[i] != com->specificator && str[i] != '\0')
	{
		if (!input_symb(arg, str[i]))
			res_str = help_search(res_str, com, str, &i);
		else if (str[i] == '\0')
		{
			res_str = ft_strnew(i);
			res_str = ft_strcpy(res_str, str);
			ft_putstr((unsigned char const *)str);
			return (res_str);
		}
		if (str[i] != '\0')
			i++;
	}
	if (res_str)
		com->error = 5;
	return (res_str);
}
