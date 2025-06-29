#ifndef GAME_H_
#define GAME_H_
#include <stdio.h>

typedef struct snake{
    int x;
    int y;
    struct snake *prev;
}snake_s;

typedef struct fruit{
    int x;
    int y;
}fruit_s;

/*       1
 *       |
 *   0 —   — 2
 *       |
 *       3
 */
typedef enum{left,up,right,down} direction;

void push(snake_s **head, int x, int y);
void snake_init(snake_s **head);
void print_snake(snake_s *head);
void move_right(snake_s **head);
void move_left(snake_s **head);
void move_up(snake_s **head);
void move_down(snake_s **head);
void take_fruit(snake_s **head, fruit_s fruit);
int detect_collision(snake_s *head);

#endif