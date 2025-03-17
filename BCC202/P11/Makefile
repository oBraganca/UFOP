all: pratica.o heap.o
	@gcc pratica.o heap.o -o exe
	@rm -r pratica.o heap.o
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
heap.o: heap.c
	@gcc heap.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval heap.c pratica.c -Wall
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval

