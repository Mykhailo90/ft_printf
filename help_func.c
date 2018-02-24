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

char 					*add_null_after_w(t_list *com, char *str)
{
	char	*tmp;
	char	*del;
	int 	len;

	del = str;
	len = ft_atoi(com->width) - (int)ft_strlen(str);
	tmp = ft_strnew(len);
	full_n(tmp, 0, len);
	str = ft_strjoin(str, tmp);
	free(del);
	free(tmp);
	return (str);
}

char 					*add_null_before_pr(t_list *com, char *str)
{
	char	*tmp;
	char	*del;
	int 	len;

	del = str;
	len = ft_atoi(com->precision) - (int)ft_strlen(str);
	tmp = ft_strnew(len);
	full_n(tmp, 0, len);
	str = ft_strjoin(tmp, str);
	free(del);
	free(tmp);
	return (str);
}

char					*prepare_str_p(t_list *com, char *str, char ch)
{
	if (com->precision && ft_atoi(com->precision) > (int)ft_strlen(str))
		str = add_null_before_pr(com, str);
	str = add_hesh(com, str, ch);
	if (!com->precision && com->width &&
		ft_atoi(com->width) > (int)ft_strlen(str) &&
		input_symb(com->flags, '0') && !input_symb(com->flags, '-'))
	{
		str = add_null_after_w(com, str);
	}
	
	if (com->precision && com->width &&
		ft_atoi(com->width) > (int)ft_strlen(str)
		&& !input_symb(com->flags, '-'))
		str = add_esp(str, com);
	if (com->width && !input_symb(com->flags, '0') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	if (com->width && input_symb(com->flags, '-') &&
		(ft_atoi(com->width) > (int)ft_strlen(str)))
		str = add_esp(str, com);
	return (str);
}


char				*search_sp_p(unsigned long int tmp, t_list *com, char ch)
{
	char				*res_str;
	
	res_str = NULL;
	res_str = ft_itoa_base(tmp, ch);
	return (prepare_str_p(com, res_str, ch));
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
