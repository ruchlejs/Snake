#include <stdlib.h>
#include "game.h"

void snake_init(snake_s **head){
    int i;
    for(i = 0; i < 3; i++){
        push(head,2-i,0);
    }
}

void push(snake_s **head, int x, int y){
    snake_s *temp = *head;
    temp = malloc(sizeof(snake_s));
    temp->x = x;
    temp->y = y;
    temp->prev = *head;
    *head = temp;
}