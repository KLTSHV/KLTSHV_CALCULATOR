.PHONY: run clear all

all: main

FLAG = -lm -Wextra -Wall

main: main.o 2xFuncs.o 8xFuncs.o 16xFuncs.o 
	gcc $(FLAG) main.o 2xFuncs.o 8xFuncs.o 16xFuncs.o -o main
main.o: main.c
	gcc $(FLAG) -c main.c 

2xFuncs.o: 2xFuncs.c
	gcc $(FLAG) -c 2xFuncs.c

8xFuncs.o: 8xFuncs.c
	gcc  $(FLAG) -c 8xFuncs.c

16xFuncs.o: 16xFuncs.c
	gcc $(FLAG) -c 16xFuncs.c

clear:
	rm -f main *.o
	
run: main
	./main
