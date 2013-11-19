#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/11/19 19:02:03 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

INC = ./inc
SRC_DIR = ./src
UNITS = ft_memset.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_memcpy.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -g
LNK = ar rcs

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(UNITS_O)
	@$(LNK) $(NAME) $^

%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c -I$(INC) -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
