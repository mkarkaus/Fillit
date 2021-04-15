# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 17:36:20 by sreijola          #+#    #+#              #
#    Updated: 2021/04/15 15:31:04 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS_FILES = main.c validate.c pc.c board.c solve.c
SRCS_PATH = ./srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIB = libft/libft.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@$(GCC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "Library and fillit made"

clean:
	@make -C libft clean
	@echo "Object files removed from libft. Beep-Bop"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Binaries and object files gone." 

re: fclean all
	@echo "All good again"
