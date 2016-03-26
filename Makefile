NAME=libft.a

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -g
LDFLAGS = rcs
CC = gcc
LD = ar

SHELL=/bin/bash
COUNT=0

SRCS=$(shell find $(SRC_DIR) -maxdepth 1 -name "*.c")
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
NOBJS=$(shell echo $(OBJS) | wc -w)

$(NAME): $(OBJS)
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Linking $@" "$$PRCT" ; \
	$(LD) $(LDFLAGS) $@ $^; \
	printf "\r\033[K[$(CC)|%s%%] Linked $@\n" "$$PRCT";

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir -p $(OBJ_DIR); fi
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Compiling %s into %s ... " "$$PRCT" "$<" "$@"; \
	$(CC) $(CFLAGS) -c -o $@ $^; \
	$(eval COUNT = $(shell echo "$(COUNT) + 1" | bc) ) \
	printf "\r\033[K[$(CC)|%s%%] Compiled %s into %s ... " "$$PRCT" "$<" "$@"; \

all: $(NAME)

clean:
	@NOBJS=$$(find $(OBJ_DIR) -maxdepth 1 -name "*.o" | wc -w); \
	[ $$NOBJS -gt 0 ] && echo "Removing $$NOBJS object(s)."; \
	rm -f $(OBJS);

fclean: clean
	@[ -e $(NAME) ] && echo "Removing target ($(NAME))."; \
	rm -f $(NAME);

re: fclean $(NAME)

.PHONY: clean fclean re all