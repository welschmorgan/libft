NAME=tests

all: $(NAME)

$(NAME):
	make -C atoi
	make -C atol
	make -C bzero
	make -C isalnum
	make -C isalpha

clean:
	make clean -C atoi
	make clean -C atol
	make clean -C bzero
	make clean -C isalpha
	make clean -C isalnum

fclean:
	make fclean -C atoi
	make fclean -C atol
	make fclean -C bzero
	make fclean -C isalpha
	make fclean -C isalnum

re: fclean all

.PHONY: clean fclean all re $(NAME)