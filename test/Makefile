#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/11/19 18:50:39 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = app

INC = ./inc
SRC_DIR = ./
UNITS = main.c
UNITS_O = $(UNITS:.c=.o)

SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))

FLAGS = -Wall -Wextra -Werror -g

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(UNITS_O)
	$(CC) $(FLAGS) -o $(NAME) -I$(INC) -I../inc/ $^ ../libft.a

%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<  -I$(INC)  -I../inc/

clean:
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
