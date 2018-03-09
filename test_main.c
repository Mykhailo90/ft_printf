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

	//setlocale(LC_ALL, "");
	i = LONG_MAX;
	char txt[10];
	long long rt = 0x10fd13ae0;

  // printf("%d", printf("% c", 0));


  //

  	printf("%s %s\n", NULL, "string");
   ft_printf("%s %s\n", NULL, "string");

 	//ft_printf("%d", ft_printf("% c\n", 0));
	  
//	printf("%d", printf("% c\n", 0));
	return (0);
}
