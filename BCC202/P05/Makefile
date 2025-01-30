all: pratica.o duende.o
	@gcc pratica.o duende.o -o exe
	@rm -rf *.o
pratica.o: pratica.c
		@gcc pratica.c -c
duende.o: duende.c
	@gcc duende.c -c
run:
	@./exe
val:
	@gcc -g -o exeval pratica.c duende.c -Wall -lm
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval