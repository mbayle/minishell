# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 20:28:28 by mabayle           #+#    #+#              #
#    Updated: 2019/03/22 16:35:36 by mabayle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minishell

CC = gcc
DEBUG = 0

ifeq ($(DEBUG), 0)
	CFLAGS = -Wall -Wextra -Werror -I$(INC_PATH)
else
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I$(INC_PATH)
endif

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = 

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = minishell.h

OUTPUT_TYPE = exec

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@echo "je t'aime Marion -Kali"
ifeq ($(OUTPUT_TYPE), lib)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
else
	@$(CC) $(CFLAGS) $(OBJS) -L libft/ -lft -o $(NAME)
endif
	@echo "\033[0;32m BUILD DONE \033[0m"
	@echo "                                                        "

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Deleted all .o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Deleted ft_ls\033[0m"

re: fclean all
