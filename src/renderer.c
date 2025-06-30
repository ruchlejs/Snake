#include "renderer.h"

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