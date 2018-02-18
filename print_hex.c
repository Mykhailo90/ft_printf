#include "ft_printf.h"

int ft_count(int num)
{
	
	if (num > 16)
		ft_count(num / 16);
	if (num % 16 < 10)
		ft_putchar(num % 16 + '0');
	else
		ft_putchar(num % 16 - 10 + 'a');
	return (0);
}

void print_hex(char *str)
{
	ft_count(ft_atoi(str));
	return (0);
}