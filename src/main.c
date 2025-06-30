#include <stdio.h>
#include "../include/renderer.h"
#include "../include/game.h"


int main (void){
    snake_s *head = NULL;
    snake_init(&head);
    fruit_s fruit = generate_fruit(head);
    direction direction = down;
    int score = 0;


    game_t game = {
        .window = NULL,
        .renderer = NULL,
        .text_font = NULL,
        .text_color = {255, 255, 255, 255},
        .text_rect = {0,0,0,0},
        .text_img = NULL,
    };

    if(SDL_initialize(&game)){
        printf("error during init\n");
        exit(1);
    }

    if(load_media(&game)){
        printf("error during loading media\n");
        exit(1);
    }
    
    int game_is_running = 1;

    while(game_is_running){
        SDL_Event event;
        int key_pressed = 0;
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                destroy_game(&game);
                exit(EXIT_SUCCESS);
                break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    destroy_game(&game);
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    if(key_pressed)break;
                    key_pressed = 1;
                    switch(event.key.keysym.sym){
                        case SDLK_RIGHT:
                            if(direction >= 2){
                                direction = right;
                            }
                            break;
                        case SDLK_LEFT:
                            if(direction >= 2){
                                direction = left;
                            }
                            break;
                        case SDLK_UP:
                            if(direction < 2){
                                direction = up;
                            }
                            break;
                        case SDLK_DOWN:
                            if(direction < 2){
                                direction = down;
                            }
                            break;
                        default:
                        break;
                    }
                    break;
            }
            
            default:
                break;
            }
        }
        move_forward(&head, direction, &fruit, &score);

        //define grass color for the background
        draw_background(game.renderer);
        print_score(&game, score);

        draw_fruit(game.renderer, fruit);

        draw_snake(game.renderer, head);

        SDL_RenderPresent(game.renderer);
        SDL_Delay(120);
    }
    
    destroy_game(&game);
    printf("Everything went right\n");

    return 0;
}