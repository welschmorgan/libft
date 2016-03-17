TEST_NAME:=""
TEST_OBJS:=""
TEST_DIR:=""
LIBFT:="libft"

CFLAGS:=-Wall -Werror -Wextra $$INC -ggdb
LDFLAGS:=-L$${LIBFT} -lft_d
CC:=gcc

all: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT) -I$(LIBFT)/includes

clean:
	@if [ $${#TEST_OBJS} -gt 0 ]; then \
		echo $${TEST_NAME}: $$(rm -f $$TEST_OBJS && echo "Removed $${#TEST_OBJS} object(s)."); \
	fi

fclean: clean
	@if [ -f $$TEST_NAME ]; then \
		echo $${TEST_NAME}: $$(rm -f $$TEST_NAME && echo "Removed executable."); \
	fi

re: fclean all

.PHONY: re fclean clean all