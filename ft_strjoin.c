/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:16:05 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:50:07 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}

unsigned char		*ft_strjoin_U(unsigned char const *s1, unsigned char const *s2)
{
	unsigned char	*res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_memalloc(ft_strlen_U(s1) + ft_strlen_U(s2) + 1)))
		return (NULL);
	ft_strcpy_U(res, s1);
	ft_strcat_U(res, s2);
	return (res);
}
