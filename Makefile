# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:21:08 by almarcos          #+#    #+#              #
#    Updated: 2023/08/30 17:24:38 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJ_FOLDER = ./obj/
SOURCES = get_next_line.c get_next_line_utils.c

OBJ = $(addprefix $(OBJ_FOLDER), $(SOURCES:.c=.o))

all: $(OBJ) $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJ)

$(OBJ_FOLDER)%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@ -I .
	ar rc $(NAME) $@

run_tests:
	
