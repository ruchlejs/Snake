all: main

main: main.o renderer.o game.o
	gcc main.o renderer.o game.o -o snake -lSDL2

main.o: main.c
	gcc -c main.c -o main.o -lSDL2

renderer.o: renderer.c
	gcc -c renderer.c -o renderer.o -lSDL2

game.o: game.c
	gcc -c game.c -o game.o

clean:
	rm -rf snake *.o