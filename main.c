#include <stdio.h>
#include "renderer.h"
#include "game.h"


int main (void){
    snake_s *head = NULL;
    snake_init(&head);
    fruit_s fruit = {0,0};
    direction direction = left;

    print_snake(head);
    // propagate_coords(&head, 1,0);
    // move_right(&head);
    move_forward(&head, direction);
    print_snake(head);
    move_forward(&head, direction);
    print_snake(head);
    direction = down;
    move_forward(&head, direction);
    print_snake(head);
    direction = left;
    move_forward(&head, direction);
    print_snake(head);
    
    
    
    // print_snake(head);
    // take_fruit(&head, fruit);
    // print_snake(head);



    // game_t game = {
    //     .window = NULL,
    //     .renderer = NULL
    // };

    // if(SDL_initialize(&game)){
    //     printf("error during init\n");
    //     exit(1);
    // }


    // SDL_Rect rect = {0,0,20,20};

    
    // int game_is_running = 1;

    // while(game_is_running){
    //     SDL_Event event;
    //     while(SDL_PollEvent(&event)){
    //         switch (event.type)
    //         {
    //         case SDL_QUIT:
    //             destroy_game(&game);
    //             exit(EXIT_SUCCESS);
    //             break;

    //         case SDL_KEYDOWN:
    //         switch(event.key.keysym.sym){
    //             case SDLK_ESCAPE:
    //                 destroy_game(&game);
    //                 exit(EXIT_SUCCESS);
    //                 break;
    //             case SDLK_RIGHT:
    //                 rect.x += 20;
    //                 break;
    //             case SDLK_LEFT:
    //                 rect.x -= 20;
    //                 break;
    //             case SDLK_UP:
    //                 rect.y -= 20;
    //                 break;
    //             case SDLK_DOWN:
    //                 rect.y += 20;
    //                 break;
    //             default:
    //             break;
    //         }
            
    //         default:
    //             break;
    //         }
    //     }

    //     //define grass color for the background
    //     SDL_SetRenderDrawColor(game.renderer, 34, 139, 34, 255);
    //     SDL_RenderClear(game.renderer);

    //     //draw a rectangle
    //     SDL_SetRenderDrawColor(game.renderer, 34, 0, 255, 255);
    //     SDL_RenderFillRect(game.renderer,&rect);

    //     SDL_RenderPresent(game.renderer);
    //     SDL_Delay(16);
    // }
    
    // destroy_game(&game);
    // printf("Everything went right\n");

    return 0;
}