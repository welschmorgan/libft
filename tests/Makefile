#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2014/02/19 05:11:11 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_suite
UNIT_TESTS = $(shell ls units)
UNITS = $(patsubst %, src/%.c, $(UNIT_TESTS))
OBJECTS = $(patsubst %, obj/%.o, $(UNIT_TESTS))

LIBFT = ../

all: $(NAME)

$(NAME): $(OBJECTS) obj/main.o
	@printf "\r\033[KLinking %s\n" $@
	@clang -o $@ $^ -L$(LIBFT) -lft_d

obj/%.o: src/%.c
	@printf "\r\033[KCompiling unit: \t%s %10s" $< "              "
	@clang -c -o $@ $< -I$(LIBFT)/inc -Iinc

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re