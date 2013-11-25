NAME=tests

all: $(NAME)

$(NAME):
#	make -C strsplit
#	make -C itoa
	make -C atoi
#	make -C atol
	make -C bzero
	make -C isalnum
	make -C isalpha
	make -C isascii
	make -C isdigit
	make -C isprint

clean:
#	make clean -C strsplit
#	make clean -C itoa
	make clean -C atoi
#	make clean -C atol
	make clean -C bzero
	make clean -C isalpha
	make clean -C isalnum
	make clean -C isascii
	make clean -C isdigit
	make clean -C isprint

fclean:
#	make fclean -C strsplit
#	make fclean -C itoa
	make fclean -C atoi
#	make fclean -C atol
	make fclean -C bzero
	make fclean -C isalpha
	make fclean -C isalnum
	make fclean -C isascii
	make fclean -C isdigit
	make fclean -C isprint

re: fclean all

run: all
	sh test.sh

.PHONY: clean fclean all re $(NAME)
