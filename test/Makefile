#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/11/22 18:31:33 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = app

UNITS = main.c char_tests.c str_tests.c mem_tests.c
UNITS_O = $(UNITS:.c=.o)

LIBFT_DIR = .

INC_DIR = -I./ -I$(LIBFT_DIR)/inc/
SRC_DIR = ./test
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))

FLAGS = -Wall -Wextra -Werror -g

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(UNITS_O)
	$(CC) $(FLAGS) $(INC_DIR) -o $(NAME) $^ $(LIBFT_DIR)/libft.a

%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INC_DIR) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
