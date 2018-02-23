/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:45:03 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/20 13:45:04 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "ft_printf.h"

int			main(void)
{
	long long		i;

	setlocale(LC_ALL, "");
	i = LONG_MAX;
	char txt[10];
	long long rt = 0x10fd13ae0;

   printf("{%3c}\n", 0);

   
 	ft_printf("{%3c}\n", 0);
	  
	//printf("%d", printf("%.0d", 0));
	return (0);
}
