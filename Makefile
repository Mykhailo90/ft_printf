#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 12:37:49 by msarapii          #+#    #+#              #
#    Updated: 2017/11/21 18:51:50 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_printf.a
SRCS=ft_putchar.c ft_putstr.c
OBJ=$(SRC:.c=.o)
HEADERS=./ft_printf.h

all: $(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADERS)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: 
	rm -rf $(NAME) $(OBJ)

re: fclean all
