# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 11:43:31 by nbaldes           #+#    #+#              #
#    Updated: 2025/08/18 10:00:42 by utilisateur      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = pipex.c \
parsing_file.c \
parsing_cmd.c \
ft_split.c \
utils.c \

OBJ = $(SRC:.c=.o)

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB)
	$(CC) $(OBJ) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
