all: pratica.o matriz.o
	@gcc pratica.o matriz.o -o exe -lm
	@rm -r pratica.o matriz.o
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
matriz.o: matriz.c
	@gcc matriz.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval pratica.c matriz.c -Wall -lm
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval

