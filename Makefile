# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:21:08 by almarcos          #+#    #+#              #
#    Updated: 2023/08/31 18:18:02 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
GREEN = "\033[1;32m"
RESET = "\033[0m"

SOURCES = get_next_line.c get_next_line_utils.c
BONUS_SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c

SOURCES_TEST_FOLDER = ./tests/project_test/mandatory/
SOURCES_TEST_BONUS_FOLDER = ./tests/project_test/bonus/

all: $(OBJECTS_FOLDER)

$(OBJECTS_FOLDER):
	mkdir -p $(OBJECTS_FOLDER)

test:
	@echo $(GREEN)Mandatory$(RESET)
	@echo $(GREEN)BUFFER_SIZE=1$(RESET)
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_1.c -D BUFFER_SIZE=1 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_2.c -D BUFFER_SIZE=1 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_3.c -D BUFFER_SIZE=1 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_4.c -D BUFFER_SIZE=1 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_5.c -D BUFFER_SIZE=1 -lbsd 
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=42$(RESET)
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_1.c -D BUFFER_SIZE=42 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_2.c -D BUFFER_SIZE=42 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_3.c -D BUFFER_SIZE=42 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_4.c -D BUFFER_SIZE=42 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_5.c -D BUFFER_SIZE=42 -lbsd 
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=3$(RESET)
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_1.c -D BUFFER_SIZE=3 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_2.c -D BUFFER_SIZE=3 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_3.c -D BUFFER_SIZE=3 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_4.c -D BUFFER_SIZE=3 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_5.c -D BUFFER_SIZE=3 -lbsd 
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=200$(RESET)
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_1.c -D BUFFER_SIZE=200 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_2.c -D BUFFER_SIZE=200 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_3.c -D BUFFER_SIZE=200 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_4.c -D BUFFER_SIZE=200 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_5.c -D BUFFER_SIZE=200 -lbsd 
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=999999$(RESET)
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_1.c -D BUFFER_SIZE=999999 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_2.c -D BUFFER_SIZE=999999 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_3.c -D BUFFER_SIZE=999999 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_4.c -D BUFFER_SIZE=999999 -lbsd 
	@./a.out
	@$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST_FOLDER)test_5.c -D BUFFER_SIZE=999999 -lbsd 
	@./a.out

bonus_test:
	@echo $(GREEN)Bonus$(RESET)
	@echo $(GREEN)BUFFER_SIZE=1$(RESET)
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_1.c -D BUFFER_SIZE=1 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_2.c -D BUFFER_SIZE=1 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_3.c -D BUFFER_SIZE=1 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_4.c -D BUFFER_SIZE=1 -lbsd
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=13$(RESET)
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_1.c -D BUFFER_SIZE=13 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_2.c -D BUFFER_SIZE=13 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_3.c -D BUFFER_SIZE=13 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_4.c -D BUFFER_SIZE=13 -lbsd
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=200$(RESET)
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_1.c -D BUFFER_SIZE=200 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_2.c -D BUFFER_SIZE=200 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_3.c -D BUFFER_SIZE=200 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_4.c -D BUFFER_SIZE=200 -lbsd
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=3$(RESET)
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_1.c -D BUFFER_SIZE=3 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_2.c -D BUFFER_SIZE=3 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_3.c -D BUFFER_SIZE=3 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_4.c -D BUFFER_SIZE=3 -lbsd
	@./a.out
	@echo $(GREEN)BUFFER_SIZE=99999$(RESET)
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_1.c -D BUFFER_SIZE=99999 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_2.c -D BUFFER_SIZE=99999 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_3.c -D BUFFER_SIZE=3 -lbsd
	@./a.out
	@$(CC) $(CFLAGS) $(BONUS_SOURCES) $(SOURCES_TEST_BONUS_FOLDER)test_4.c -D BUFFER_SIZE=3 -lbsd
	@./a.out
