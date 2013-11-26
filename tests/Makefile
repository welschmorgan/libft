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
	make -C strlcat
	make -C strlen
	make -C strncat
	make -C strncmp
	make -C strncpy
	make -C strstr
	make -C strnstr

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
	make clean -C strlcat
	make clean -C strlen
	make clean -C strncat
	make clean -C strncmp
	make clean -C strncpy
	make clean -C strstr
	make clean -C strnstr

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
	make fclean -C strlcat
	make fclean -C strlen
	make fclean -C strncat
	make fclean -C strncmp
	make fclean -C strncpy
	make fclean -C strstr
	make fclean -C strnstr

re: fclean all

run: all
	sh test.sh

.PHONY: clean fclean all re $(NAME)
