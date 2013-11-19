INC_DIR="inc/"
SRC_DIR="src/"
OBJ_DIR="obj/"

NAME=libft
SRCS=main.c\
	ft_bzero.c\
	ft_memset.c\
	ft_strlen.c

$(NAME): gcc $(SRCS) -o $(NAME)
	
all: $(NAME)

clean:
	@rm *.o

fclean: clean
	@rm $(NAME)

re: fclean
	$(NAME)
