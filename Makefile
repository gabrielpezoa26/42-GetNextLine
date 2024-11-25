# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 15:35:56 by gcesar-n          #+#    #+#              #
#    Updated: 2024/11/25 17:00:30 by gcesar-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME:= get_next_line.a
HDR:= get_next_line.h

SRC_FILES:=	get_next_line.c\
			get_next_line_utils.c\

OBJ_FILES := $(SRC_FILES:.c=.o)

%.o: %.c $(HDR)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
			ar rcs $@ $^

all: $(NAME)

clean:
		rm -f $(OBJ_FILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
