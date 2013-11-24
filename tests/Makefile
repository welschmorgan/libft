NAME=tests

all: $(NAME)

$(NAME):
	make -C atoi
	make -C atol
	make -C bzero
	make -C isalnum
	make -C isalpha
	make -C strsplit
	make -C itoa

clean:
	make clean -C atoi
	make clean -C atol
	make clean -C bzero
	make clean -C isalpha
	make clean -C isalnum
	make clean -C strsplit
	make clean -C itoa

fclean:
	make fclean -C atoi
	make fclean -C atol
	make fclean -C bzero
	make fclean -C isalpha
	make fclean -C isalnum
	make fclean -C strsplit
	make fclean -C itoa

re: fclean all

run: all
	sh test.sh

.PHONY: clean fclean all re $(NAME)
