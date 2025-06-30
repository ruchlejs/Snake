#include "../include/renderer.h"

void destroy_game(game_t *game){
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}

int SDL_initialize(game_t *game){
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("error initializing SDL: %s\n",SDL_GetError());
        return -1;
    }

    if(!(game->window = SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 
                                         WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN))){
        printf("error creating the window: %s\n",SDL_GetError());
        SDL_Quit();
        return -1;
    }

    if(!(game->renderer = SDL_CreateRenderer(game->window,-1,SDL_RENDERER_ACCELERATED))){
        printf("error creating the renderer: %s\n",SDL_GetError());
        SDL_DestroyWindow(game->window);
        SDL_Quit();
        return -1;
    }

    return 0;
}

void draw_background(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
    SDL_RenderClear(renderer);
}

void draw_fruit(SDL_Renderer *renderer, fruit_s fruit){
    SDL_Rect rect = {TILE_SIZE * fruit.x, TILE_SIZE * fruit.y, TILE_SIZE, TILE_SIZE};
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_snake(SDL_Renderer *renderer, snake_s *head){
    
    while(head != NULL){
        SDL_SetRenderDrawColor(renderer, 0,0,255,255);
        SDL_Rect rect = {TILE_SIZE * head->x, TILE_SIZE * head->y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 20,20,240,255);
        SDL_RenderDrawRect(renderer, &rect);
        head = head->prev;
    }
}
