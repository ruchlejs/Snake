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

void print_snake(snake_s *head){
    snake_s *temp = head;
    printf("Head -> ");
    while(temp!=NULL){
        printf("Pos: x:%d y:%d\n",temp->x,temp->y);
        temp = temp->prev;
    }
}

void move_right(snake_s **head){
    propagate_coords(head,(*head)->x+1, (*head)->y);
}

void move_left(snake_s **head){
    propagate_coords(head,(*head)->x-1, (*head)->y);
}

void move_up(snake_s **head){
    propagate_coords(head,(*head)->x, (*head)->y-1);
}

void move_down(snake_s **head){
    propagate_coords(head,(*head)->x, (*head)->y+1);
}

void take_fruit(snake_s **head, fruit_s fruit){
    push(head, fruit.x, fruit.y);
}

int detect_collision(snake_s *head){
    snake_s *temp = head;
    while(temp != NULL){
        if(temp->x == head->x && temp->y == head->y){
            return 1;
        }
    }
    return 0;
}

void move_forward(snake_s **head, direction direction){
    switch (direction){
        case left:
            move_left(head);
            break;
        
        case right:
            move_right(head);
            break;
    
        case up:
            move_up(head);
            break;

        case down:
            move_down(head);
            break;

        default:
            break;
    }
}

void propagate_coords(snake_s **head, int x, int y){
    printf("x: %d\n",x);
    snake_s *temp = *head;
    while(temp != NULL){
        int temp_x = temp->x;
        int temp_y = temp->y;
        temp->x = x;
        temp->y = y;
        
        temp = temp->prev;
        x = temp_x;
        y = temp_y;
    }
}