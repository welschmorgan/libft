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
	make -C strcat
	make -C strchr
	make -C strcmp
	make -C strcpy
	make -C strdup

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
	make clean -C strcat
	make clean -C strchr
	make clean -C strcmp
	make clean -C strcpy
	make clean -C strdup

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
	make fclean -C strcat
	make fclean -C strchr
	make fclean -C strcmp
	make fclean -C strcpy
	make fclean -C strdup

re: fclean all

run: all
	sh test.sh

.PHONY: clean fclean all re $(NAME)
