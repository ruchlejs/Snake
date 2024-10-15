all: main

main: main.c
	gcc -o hello_sd main.c `sdl2-config --cflags --libs`
