all: instrucao.o memoria.o main.c
	gcc -o main main.c instrucao.o memoria.o -lm -Wall

instrucao.o: instrucao.c
	gcc -o instrucao.o -c instrucao.c
	
memoria.o: memoria.c
	gcc -o memoria.o -c memoria.c
	
clean:
	rm -f *.o main

run:
	./main
