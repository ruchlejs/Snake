#include <stdlib.h>
#include "../include/game.h"

void snake_init(snake_s **head){
    int i;
    for(i = 0; i < INIT_SIZE; i++){
        push(head,INIT_SIZE -1 - i,0);
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
    if(head->x < 0 || head->x >= GAME_WIDTH || head->y < 0 || head->y >= GAME_HEIGHT){
        return 1;
    }
    snake_s *temp = head;
    temp = temp->prev;
    while(temp != NULL){
        if(temp->x == head->x && temp->y == head->y){
            return 1;
        }
        temp = temp->prev;
    }
    return 0;
}

void move_forward(snake_s **head, direction direction, fruit_s *fruit){
    if(is_fruit(*head,direction, *fruit)){
        take_fruit(head, *fruit);
        *fruit = generate_fruit(*head);
        return;
    }

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
    if(detect_collision(*head)){
        game_over();
    }
}

void propagate_coords(snake_s **head, int x, int y){
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

int is_fruit(snake_s *head, direction direction, fruit_s fruit){
    switch(direction){
        case left:
        if(head->x-1 == fruit.x && head->y == fruit.y){
            return 1;
        }
            break;

        case right:
        if(head->x+1 == fruit.x && head->y == fruit.y){
            return 1;
        }
            break;

        case up:
        if(head->x == fruit.x && head->y-1 == fruit.y){
            return 1;
        }
            break;

        case down:
        if(head->x == fruit.x && head->y+1 == fruit.y){
            return 1;
        }
            break;

        default:
            break;
    }
    
    return 0;
}

void victory(void){
    printf("Congratulation, you win!\n");
    exit(EXIT_SUCCESS);
}

void game_over(void){
    printf("Game Over, try again!!\n");
    exit(EXIT_SUCCESS);
}

fruit_s generate_fruit(snake_s *head){
    int x = -1;
    int y = -1;

    snake_s *temp = head;
    int collision = 1;
    while(collision){
        collision = 0;
        x = rand() % GAME_WIDTH -1;
        y = rand() % GAME_HEIGHT -1;

        while(temp != NULL){
            if(x == temp->x && y == temp->y){
                collision = 1;
                break;
            }
            temp = temp->prev;
        }
    }
    return (fruit_s){x,y};
}

void print_fruit(fruit_s fruit){
    printf("fruit -> x: %d, y: %d\n",fruit.x,fruit.y);
}