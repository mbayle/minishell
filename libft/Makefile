# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 03:26:28 by mabayle           #+#    #+#              #
#    Updated: 2019/07/22 09:18:03 by mabayle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strrchr.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_isspace.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strjoin_free.c \
	  ft_strjoin_one.c \
	  ft_strjoin_onef.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_tablen.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  get_next_line.c \
	  ft_dlstnew.c \
	  ft_add_str_to_board.c \
	  ft_free_array.c \
	  ft_split_whitespaces.c

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = libft.h

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@echo "                                                        "
	@ar rc $(NAME) $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling libft :\033[0m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Deleted all .o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Deleted libft.a\033[0m"

re: fclean all
