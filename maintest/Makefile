NAME = maintest
EXTRA = -Wall -Werror -Wextra -std=c89 -pedantic -O3 -g -I../

all: $(NAME)

$(NAME): main.o
	gcc $(EXTRA) main.o -o $(NAME) -L../ -lft

main.o: main.c
	gcc $(EXTRA) main.c -c -o main.o

clean:
	rm -f *.o

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: clean fclean re all
