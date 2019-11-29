# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 17:37:50 by mkarkaus          #+#    #+#              #
#    Updated: 2019/11/27 18:30:35 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/*.c

FLAGS = -Wall -Werror -Wextra

HEAD = includes/*.h

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) $(HEAD)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
