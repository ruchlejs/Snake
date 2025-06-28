#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>

#define WINDOW_TITLE "Snake"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define TILE_SIZE 20
#define DIMENSION 10


typedef struct game_s{
    SDL_Window *window;
    SDL_Renderer *renderer;
}game_t;

int SDL_initialize(game_t *game);
void destroy_game(game_t *game);
#endif