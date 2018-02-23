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

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_atoi.c ft_bzero.c ft_putnbr.c ft_isdigit.c ft_itoa.c ft_memalloc.c \
		ft_putchar.c ft_putstr.c ft_strcmp.c ft_strncpy.c ft_strlen.c \
		ft_is_it_space.c ft_strjoin.c ft_strcpy.c ft_strcat.c specificator.c \
		flags.c width.c precision.c ft_strdel.c ft_strnew.c ft_itoa_u.c\
		ft_memdel.c size.c prepare_str_d.c help_add_func.c \
		convert.c search_prepare_func.c search_sp_func.c ft_is_it_space.c\
		convert_count.c add_prepare.c add_func1.c help_func.c ftpf.c

OBJ = $(SRC:.c=.o)

# HEADERS=./ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: 
	rm -rf $(NAME) $(OBJ)

re: fclean all

mainflag: 
	@gcc $(FLAGS) test_main.c libftprintf.a
	@./a.out

main:
	@cc test_main.c libftprintf.a
	@./a.out
