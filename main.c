/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:34:49 by msarapii          #+#    #+#             */
/*   Updated: 2018/01/30 16:34:51 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// Вставить костыль на спецификатор процентов, чтобы если после символа проценты продолжало печатать

int		is_input_spec(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'd' || ch == 'i' || ch == '0' ||
		ch == 'x' || ch == 'X' || ch == 'u' || ch == 'f' || ch == 'F' ||
		ch == 'e' || ch == 'E' || ch == 'a' || ch == 'A' || ch == 'g' ||
		ch == 'G' || ch == 'n' || ch == 'p')
		return (ch - '0');
	return (-1);
}

void	search_specificator(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		i++;
	}
}

void	test(va_list argptr, char *str, char ch)
{
	if (is_input_spec(ch) == ('d' - '0'))
	{
		ft_putnbr(va_arg(argptr, int));
	}
}

void	ft_printf(char *str, ...)
{
	char ch;
	va_list argptr;
	int i;
	char *head;

	i = 0;
	head = str;
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			search_specificator(&str[++i]);
			test(argptr, head, str[i]);
			i++;
		}
		ft_putchar(str[i]);
		i++;
	}
	va_end(argptr);
}


int		main(void)
{
	int i;
	int n;
	i = 1134;
	n = 777;
	ft_printf("Eto idend D = %d i snova D1 = %d\n", i, n);
	printf("Eto idend D = %d i snova D1 = %d\n", i, n);
	return 0;
}