# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:22:41 by sgomez-p          #+#    #+#              #
#    Updated: 2022/10/20 15:56:32 by sgomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC= gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf_hexlow.c ft_printf_hexup.c ft_printf_int.c \
ft_printf_str.c ft_printf_unsigned_int.c ft_printf_void_hex.c check_format.c \
ft_printf_char.c ft_printf_char.c ft_itoa_base.c \
utils.c ft_printf_per.c\


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar -rs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re