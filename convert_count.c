/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:06:39 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 12:06:40 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char		*convert_in_str(wchar_t *tmp)
{
	int				len;
	unsigned char	*res;

	len = size_wt(tmp);
	res = (unsigned char *)ft_strnew(len);
	func_help1(tmp, res, len);
	return (res);
}

unsigned char		*search_wt_str(va_list argptr, t_list *com)
{
	wchar_t			*tmp;
	unsigned char	*res_str;
	char			nn[] = "(null)";
	
	res_str = NULL;
	tmp = NULL;
	tmp = va_arg(argptr, wchar_t *);
	if (tmp == NULL)
		res_str = (unsigned char *)nn;
	else if (com->precision && (ft_atoi(com->precision) < size_wt(tmp)))
		res_str = convert_in_str1(tmp, ft_atoi(com->precision));
	else
		res_str = convert_in_str(tmp);
	return (res_str);
}

char				*ft_count_xv(unsigned long long num, char *res, char ch)
{
	char			*tmp;

	tmp = ft_strnew(1);
	if (num > 0)
		res = ft_count_xv(num / 16, res, ch);
	if (num % 16 < 10 && num != 0)
	{
		tmp[0] = (num % 16 + '0');
		res = ft_strjoin(res, tmp);
	}
	else if (num != 0)
	{
		tmp[0] = (ch == 'x' || ch == 'p') ? (num % 16 - 10 + 'a') :
								(num % 16 - 10 + 'A');
		res = ft_strjoin(res, tmp);
	}
	free(tmp);
	return (res);
}

char				*ft_count_ov(unsigned long long num, char *res, char ch)
{
	char			*tmp;

	tmp = ft_strnew(1);
	if (num > 7)
		res = ft_count_ov(num / 8, res, ch);
	tmp[0] = (num % 8 + '0');
	res = ft_strjoin(res, tmp);
	free(tmp);
	return (res);
}

char				*ft_itoa_base(unsigned long long number, char ch)
{
	char			*res;

	res = ft_strnew(1);
	if (number == 0)
		res[0] = '0';
	else if (ch == 'x' || ch == 'X' || ch == 'p')
		res = ft_count_xv(number, res, ch);
	else if (ch == 'O' || ch == 'o')
		res = ft_count_ov(number, res, ch);
	return (res);
}
