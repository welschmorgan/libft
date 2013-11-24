NAME=atoi.app
CC=gcc -Wall -Werror -Wextra -pedantic -std=c89
SRCS=*.c
OBJS=$(SRCS=*.c:*.o)
INC=-I../ -I../../
LIBS=../../libft.a
TARGET=../$(NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(SRCS) -o $(TARGET) $(INC) $(LIBS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: clean fclean re all