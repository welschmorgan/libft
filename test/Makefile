#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 12:39:01 by mwelsch           #+#    #+#              #
#    Updated: 2016/03/17 13:58:16 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PREFIX=test_

TESTS=$(shell find . -mindepth 1 -type d | sed 's/^\.\///g' | grep -v 'common')
TESTS_UNITS=$(shell find . -mindepth 2 -maxdepth 2 -type f -name "*.c" | sed 's/^\.\///g')
TESTS_OBJS=$(patsubst %.c,%.o,$(TEST_UNITS))
TESTS_NAMES=$(patsubst %,$(PREFIX)%,$(TESTS))

COMMON_SRCS=$(shell find common -name '*.c' -type f)
COMMON_OBJS=$(patsubst %.c,%.o,$(COMMON_SRCS))

LIBFT=/nfs/2013/m/mwelsch/Dev/Projects/libft

INC=-I../includes -I. -I./common -I$(LIBFT)/includes -I$(LIBFT)
PREFIX=test_
SUFFIX=

all: $(COMMON_OBJS) $(TESTS_NAMES)

%:
	TEST=$$(echo $@ | sed 's/^$(PREFIX)//g'); \
	echo "Building $$TEST"; \
	make \
	--no-print-directory \
	-e TEST_DIR="$$TEST" \
	-e TEST_NAME="$(PREFIX)$$TEST" \
	-e TEST_UNITS="$$(find $$TEST -mindepth 2 -type d | sed 's/^\.\///g')" \
	-e TEST_OBJS="$(patsubst %.c,%.o,$$TEST_UNITS)" \
	-e LIBFT="$(LIBFT)" \
	all \
	-f ../test.mak \
	-C $$TEST; \

common/%.o: common/%.c
	@printf "building $@ ... "; \
	$(CC) -c -o $@ $< $(CFLAGS) $(INC); \
	printf "done\n"

clean:
	@rm -f $(COMMON_OBJS)
	@for TEST in ${TESTS}; do \
		make \
		--no-print-directory \
		-e TEST_DIR="$$TEST" \
		-e TEST_NAME="$(PREFIX)$$TEST" \
		-e TEST_UNITS="$$(find $$TEST -mindepth 2 -type d | sed 's/^\.\///g')" \
		-e TEST_OBJS="$(patsubst %.c,%.o,$$TEST_UNITS)" \
		-e LIBFT="$(LIBFT)" \
		clean \
		-f ../test.mak \
		-C $$TEST; \
	done

fclean: clean
	@for TEST in ${TESTS}; do \
		make \
		--no-print-directory \
		-e TEST_DIR="$$TEST" \
		-e TEST_NAME="$(PREFIX)$$TEST" \
		-e TEST_UNITS="$$(find $$TEST -mindepth 2 -type d | sed 's/^\.\///g')" \
		-e TEST_OBJS="$(patsubst %.c,%.o,$$TEST_UNITS)" \
		-e LIBFT="$(LIBFT)" \
		fclean \
		-f ../test.mak \
		-C $$TEST; \
	done

re: fclean all

.PHONY: all re clean fclean
