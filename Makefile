NAME=libft.a
NAME=libft_d.a

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -g
LDFLAGS = rcs
CC = gcc
LD = ar

SHELL=/bin/bash
COUNT=0

SRCS=$(shell find $(SRC_DIR) -maxdepth 2 -name "*.c")
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%_d.o,$(SRCS))
NOBJS=$(shell echo $(OBJS) | wc -w)

default: all
all: debug release
debug: $(NAME_D)
release: $(NAME)

$(NAME): $(OBJS)
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Linking $@" "$$PRCT" ; \
	$(LD) $(LDFLAGS) $@ $^; \
	printf "\r\033[K[$(CC)|%s%%] Linked $@\n" "$$PRCT";

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@DIR=$$(dirname $@); \
	if [ ! -d "$$DIR" ]; then mkdir -p $$DIR; fi
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Compiling %s into %s ... " "$$PRCT" "$<" "$@"; \
	$(CC) $(CFLAGS) -c -o $@ $^; \
	$(eval COUNT = $(shell echo "$(COUNT) + 1" | bc) ) \
	printf "\r\033[K[$(CC)|%s%%] Compiled %s into %s ... " "$$PRCT" "$<" "$@"; \

$(NAME_D): $(OBJS_D)
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Linking $@" "$$PRCT" ; \
	$(LD) $(LDFLAGS) $@ $^; \
	printf "\r\033[K[$(CC)|%s%%] Linked $@\n" "$$PRCT";

$(OBJ_DIR)/%_d.o: $(SRC_DIR)/%.c
	@DIR=$$(dirname $@); \
	if [ ! -d "$$DIR" ]; then mkdir -p $$DIR; fi
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Compiling %s into %s ... " "$$PRCT" "$<" "$@"; \
	$(CC) $(CFLAGS) -ggdb -c -o $@ $^; \
	$(eval COUNT = $(shell echo "$(COUNT) + 1" | bc) ) \
	printf "\r\033[K[$(CC)|%s%%] Compiled %s into %s ... " "$$PRCT" "$<" "$@"; \

clean:
	@NOBJS=$$(find $(OBJ_DIR) -maxdepth 2 -name "*.o" | wc -w); \
	[ $$NOBJS -gt 0 ] && echo "Removing $$NOBJS object(s)."; \
	rm -f $(OBJS);

fclean: clean
	@[ -e $(NAME) ] && echo "Removing target ($(NAME))."; \
	rm -f $(NAME);

re: fclean $(NAME)

.PHONY: clean fclean re all debug release default
