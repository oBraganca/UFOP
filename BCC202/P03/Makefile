all: pratica.o carro.o
	@gcc pratica.o carro.o -o exe -lm
	@rm -r pratica.o carro.o
carro.o: carro.c
	@gcc carro.c -c -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval pratica.c carro.c -Wall -lm
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval
