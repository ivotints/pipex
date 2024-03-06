# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 12:18:19 by ivotints          #+#    #+#              #
#    Updated: 2024/03/05 12:55:59 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INCLUDE_SRC	= pipex.h
INCLUDE_DIR	= includes/
INCLUDE		= $(addprefix $(INCLUDE_DIR), $(INCLUDE_SRC))

SRC			= check.c child.c free_data.c init_forks.c main.c malloc_data.c
SRC_DIR		= src/
SRC_PATH	= $(addprefix $(SRC_DIR), $(SRC))
OBJ			= $(SRC_PATH:.c=.o)

SRCF		= ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c
SRCF_DIR	= functions/
SRCF_PATH	= $(addprefix $(SRCF_DIR), $(SRCF))
OBJF		= $(SRCF_PATH:.c=.o)

BLUE		= \033[0;34m
GREEN		= \033[0;32m
RESET		= \033[0
RED			= \033[0;31m


%.o: %.c $(INCLUDE) Makefile
			@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJF) $(OBJ)
			@$(CC) $(OBJF) $(OBJ) -o $(NAME)
			@echo "$(BLUE)$(NAME) is ready$(RESET)"

all: $(NAME)

clean:
			@$(RM) $(OBJ)
			@$(RM) $(OBJF)
			@echo "$(GREEN)Cleaned$(RESET)"
fclean: clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean bonus re




