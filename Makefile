all: main

main: main.c
	gcc -o hello_sd main.c -lSDL2