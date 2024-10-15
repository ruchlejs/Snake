#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TILE_SIZE 20  // Taille des cases
#define DIMENSION 10

int tab[DIMENSION][DIMENSION];
int over = 0;

typedef struct snake_t{
    int value;
    struct snake_t *prev;
}snake_s;

int init_window(void);
void draw_grid(SDL_Renderer *renderer);
void move_up(SDL_Renderer * renderer, int x, int y);
void move_down(SDL_Renderer * renderer);
void move_left(SDL_Renderer * renderer);
void move_right(SDL_Renderer * renderer);

int main (void){

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Erreur SDL: %s\n", SDL_GetError());
    return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur de création de fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur de création du rendu: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    //     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // SDL_RenderClear(renderer);

    // // Dessiner la grille en bleu
    // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Bleu
    // for (int x = 0; x <= SCREEN_WIDTH; x += TILE_SIZE) {
    //     SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
    // }
    // for (int y = 0; y <= SCREEN_HEIGHT; y += TILE_SIZE) {
    //     SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);
    // }

    // // Dessiner un carré blanc
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_Rect rect = {0, 0, 15, 15};
    // SDL_RenderFillRect(renderer, &rect);

    // // Mettre à jour l'écran
    // SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
    // if(init_window() != 0) exit(0);
    // draw_grid(renderer);

    // SDL_Delay(1);
        int x = 0, y = 0;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (x = 0; x <= SCREEN_WIDTH; x += TILE_SIZE) {
        SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
    }
    for (y = 0; y <= SCREEN_WIDTH; y += TILE_SIZE){
        SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);
    }

    // SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {0,0,15,15};
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    while (!over)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                over = 1;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    move_up(renderer,0,0);
                    break;
                case SDLK_DOWN:
                    move_down(renderer);
                    break;
                case SDLK_LEFT:
                    move_left(renderer);
                    break;
                case SDLK_RIGHT:
                    move_right(renderer);
                    break;
                
                case SDLK_ESCAPE:
                    over = 1;
                    break;
                }
            }
        }
    }
    


    


    
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void init_game(void){
    int i, j;
    for(i = 0; i < DIMENSION; i++){
        for(j = 0; j < DIMENSION; j++){
            tab[i][j] = 0;
        }
    }
}

int init_window(void){

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Erreur SDL: %s\n", SDL_GetError());
    return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur de création de fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur de création du rendu: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return 0;
}

void draw_grid(SDL_Renderer * renderer){
    int x = 0, y = 0;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (x = 0; x <= SCREEN_WIDTH; x += TILE_SIZE) {
        SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
    }
    for (y = 0; y <= SCREEN_WIDTH; y += TILE_SIZE){
        SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);
    }

    SDL_RenderPresent(renderer);

}

void move_up(SDL_Renderer * renderer, int x, int y){
    SDL_Rect rect = {x,y,15,15};
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderPresent(renderer);

    SDL_Rect n_rect={x,y+20, 15, 15};
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&n_rect);
    SDL_RenderPresent(renderer);
}

void move_down(SDL_Renderer * renderer){

}

void move_left(SDL_Renderer * renderer){

}

void move_right(SDL_Renderer * renderer){

}