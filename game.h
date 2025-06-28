#ifndef GAME_H_
#define GAME_H_
#include <stdio.h>

typedef struct snake{
    int x;
    int y;
    struct snake *prev;
}snake_s;

void push(snake_s **head, int x, int y);
void snake_init(snake_s **head);

#endif