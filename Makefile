# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 15:35:56 by gcesar-n          #+#    #+#              #
#    Updated: 2024/11/25 21:14:52 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME:= get_next_line.a
HDR:= get_next_line.h

SRC_FILES :=	get_next_line.c\
				get_next_line_utils.c\

OBJ_FILES := get_next_line.o \
				get_next_line_utils.o

get_next_line.o: get_next_line.c $(HDR)
				$(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o

get_next_line_utils.o: get_next_line_utils.c $(HDR)
				$(CC) $(CFLAGS) -c get_next_line_utils.c -o get_next_line_utils.o


$(NAME): $(OBJ_FILES)
				ar rcs get_next_line.a get_next_line.o get_next_line_utils.o


all: $(NAME)

clean:
		rm -f $(OBJ_FILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
