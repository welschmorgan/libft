trim: test_trim.o ../libft.a
	gcc -o $@ $^

%.o: %.c
	gcc -c -o $@ $< -I.. -g

../libft.a:
	make -C ..
all: trim
re: fclean all
clean:
	rm -f *.o
fclean: clean
	rm -f trim

.PHONY: all re clean fclean