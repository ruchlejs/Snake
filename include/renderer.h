#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

#define WINDOW_TITLE "Snake"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 540
#define TILE_SIZE 20
#define TEXT_SIZE 40
#define MARGIN 60
#define FONT_PATH "fonts/mouldy_cheese_font/MouldyCheeseRegular-WyMWG.ttf"


typedef struct game_s{
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *text_font;
    SDL_Color text_color;
    SDL_Rect text_rect;
    SDL_Texture *text_img;
}game_t;

int SDL_initialize(game_t *game);
int load_media(game_t *game);
void destroy_game(game_t *game);
void draw_background(SDL_Renderer *renderer);
void draw_fruit(SDL_Renderer *renderer, fruit_s fruit);
void draw_snake(SDL_Renderer *renderer, snake_s *head);
int print_score(game_t *game, int score);
#endif