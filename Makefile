# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:21:08 by almarcos          #+#    #+#              #
#    Updated: 2023/08/31 14:00:56 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES = get_next_line.c get_next_line_utils.c
OBJECTS_FOLDER = ./obj/
OBJECTS = $(addprefix $(OBJECTS_FOLDER), $(SOURCES:.c=.o))

SOURCES_TEST_FOLDER = ./tests/project_test/mandatory/

SOURCES_TEST = $(SOURCES_TEST_FOLDER)test_1.c $(SOURCES_TEST_FOLDER)test_2.c \
	$(SOURCES_TEST_FOLDER)test_3.c $(SOURCES_TEST_FOLDER)test_4.c \
	$(SOURCES_TEST_FOLDER)test_5.c

OBJECTS_FOLDER_TEST = $(addsuffix test/, $(OBJECTS_FOLDER))
OBJECTS_TEST = $(subst $(SOURCES_TEST_FOLDER), $(OBJECTS_FOLDER_TEST), $(SOURCES_TEST:.c=.o))

all: $(OBJECTS_FOLDER) $(OBJECTS_FOLDER_TEST) $(NAME)

$(OBJECTS_FOLDER):
	mkdir -p $(OBJECTS_FOLDER)

$(OBJECTS_FOLDER_TEST):
	mkdir -p $(OBJECTS_FOLDER_TEST)

$(NAME): $(OBJECTS)

$(OBJECTS_FOLDER)%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@ -I .
	ar rcs $(NAME) $@

$(OBJECTS_FOLDER_TEST)%.o: $(SOURCES_TEST_FOLDER)%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(OBJECTS_TEST)
	@$(CC) $(CFLAGS) $(word 1, $(OBJECTS_TEST)) $(NAME) -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(word 2, $(OBJECTS_TEST)) $(NAME) -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(word 3, $(OBJECTS_TEST)) $(NAME) -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(word 4, $(OBJECTS_TEST)) $(NAME) -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(word 5, $(OBJECTS_TEST)) $(NAME) -lbsd
	@./a.out
