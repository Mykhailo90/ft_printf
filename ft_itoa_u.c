/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:35:50 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/22 11:35:52 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t			count_symbols_u(unsigned long long n)
{
	size_t				i;

	i = 0;
	if (n == 0)
		return (i + 1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void				input_symbols_u(char *res, unsigned long long n, size_t len)
{
	res[len] = '\0';
	res = res + len - 1;
	while (len--)
	{
		*(res--) = ('0' + n % 10);
		n = n / 10;
	}
}

char					*ft_itoa_u(unsigned long long n)
{
	char				*res;
	size_t				len;
	char				*start;
	unsigned long long	num;

	num = n;
	len = count_symbols_u(num);
	if (!(res = ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	start = res;
	input_symbols_u(start, num, len);
	return (start);
}
