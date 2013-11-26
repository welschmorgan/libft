NAME = maintest
EXTRA = -std=c89 -pedantic -O3 -I../ -L../ -lft

all: $(NAME)

$(NAME): main.o
	$(CC) main.o $(EXTRA) -o $(NAME)

main.o: main.c
	$(CC) main.c -c $(EXTRA) -o main.o

clean:
	rm -f *.o

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: clean fclean re all
