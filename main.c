#include <stdio.h>
#include <SDL2/SDL.h>

#define WINDOW_TITLE "Snake"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define TILE_SIZE 20  // Taille des cases
#define DIMENSION 10

typedef struct snake_t{
    int value;
    struct snake_t *prev;
}snake_s;

typedef struct game_s{
    SDL_Window *window;
    SDL_Renderer *renderer;
}game_t;

int SDL_initialize(game_t *game);
void destroy_game(game_t *game);

int main (void){
    game_t game = {
        .window = NULL,
        .renderer = NULL
    };

    if(SDL_initialize(&game)){
        printf("error during init\n");
        exit(1);
    }

    int game_is_running = 1;

    // //define grass color for the background
    // SDL_SetRenderDrawColor(game.renderer, 34, 139, 34, 255);
    // SDL_RenderClear(game.renderer);
    // SDL_RenderPresent(game.renderer);

    // SDL_Delay(1000);

    // SDL_SetRenderDrawColor(game.renderer, 34, 139, 34, 255);
    // SDL_RenderClear(game.renderer);

    // SDL_SetRenderDrawColor(game.renderer, 34, 0, 255, 255);
    // SDL_Rect rect = {100,100,50,200};
    // SDL_RenderDrawRect(game.renderer,&rect);

    // SDL_RenderPresent(game.renderer);
    
    SDL_Rect rect = {100,100,50,200};
    while(game_is_running){
        SDL_Event event;
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
                case SDLK_RIGHT:
                    rect.x += 10;
                    break;
                default:
                break;
            }
            
            default:
                break;
            }
        }

        //define grass color for the background
        SDL_SetRenderDrawColor(game.renderer, 34, 139, 34, 255);
        SDL_RenderClear(game.renderer);

        SDL_SetRenderDrawColor(game.renderer, 34, 0, 255, 255);
        SDL_RenderDrawRect(game.renderer,&rect);

        SDL_RenderPresent(game.renderer);

        // SDL_RenderClear(game.renderer);
        // SDL_RenderPresent(game.renderer);
        SDL_Delay(16);
    }
    
    destroy_game(&game);
    printf("Everything went right\n");

    return 0;
}



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