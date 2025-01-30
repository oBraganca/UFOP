all: pratica.o recursao.o
	@gcc pratica.o recursao.o -o exe -lm
	@rm -r pratica.o recursao.o
recursao.o: recursao.c
	@gcc recursao.c -c -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval pratica.c recursao.c -Wall -lm
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval