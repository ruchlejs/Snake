all: main

main: main.c
	gcc -o snake main.c -lSDL2