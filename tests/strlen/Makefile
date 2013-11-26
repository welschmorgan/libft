NAME=strlen.app
CC=gcc -Wall -Werror -Wextra -pedantic -std=c89 -g -lc
SRCS= ../common.c *.c
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
