all: pratica.o lista.o
	@gcc pratica.o lista.o -o exe -lm
	@rm -r pratica.o lista.o
lista.o: lista.c
	@gcc lista.c -c -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval pratica.c lista.c -Wall -lm
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval
