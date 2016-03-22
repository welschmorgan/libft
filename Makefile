NAME=libft.a

CFLAGS = -Wall -Wextra -Werror -I. -g
LDFLAGS = rcs
CC = gcc
LD = ar

SHELL=/bin/bash
COUNT=0

SRCS=$(shell find . -maxdepth 1 -name "*.c")
OBJS=$(patsubst %.c,%.o,$(SRCS))
NOBJS=$(shell echo $(OBJS) | wc -w)

all: $(NAME)

$(NAME): $(OBJS)
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Linking $@" "$$PRCT" ; \
	$(LD) $(LDFLAGS) $@ $^; \
	printf "\r\033[K[$(CC)|%s%%] Linked $@\n" "$$PRCT";

%.o: %.c
	@PRCT=$$( echo "scale=1; $(COUNT) / $(NOBJS) * 100.0" | bc ); \
	printf "\r\033[K[$(CC)|%s%%] Compiling %s into %s ... " "$$PRCT" "$<" "$@"; \
	$(CC) $(CFLAGS) -c -o $@ $^; \
	$(eval COUNT = $(shell echo "$(COUNT) + 1" | bc) ) \
	printf "\r\033[K[$(CC)|%s%%] Compiled %s into %s ... " "$$PRCT" "$<" "$@"; \

clean:
	@NOBJS=$$(find . -maxdepth 1 -name "*.o" | wc -w); \
	[ $$NOBJS -gt 0 ] && echo "Removing $$NOBJS object(s)."; \
	rm -f $(OBJS);

fclean: clean
	@[ -e $(NAME) ] && echo "Removing target ($(NAME))."; \
	rm -f $(NAME);

re: fclean $(NAME)

.PHONY: clean fclean re all