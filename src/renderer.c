#include "../include/renderer.h"

void destroy_game(game_t *game){
    SDL_DestroyTexture(game->text_img);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    TTF_CloseFont(game->text_font);
    TTF_Quit();
    SDL_Quit();
}

int SDL_initialize(game_t *game){
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("error initializing SDL: %s\n",SDL_GetError());
        return -1;
    }

    if(TTF_Init()){
        printf("error initializing SDL_TTF: %s\n",TTF_GetError());
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

int load_media(game_t *game){
    game->text_font = TTF_OpenFont(FONT_PATH,TEXT_SIZE);
    if(!game->text_font){
        printf("Error loading the font: %s\n",TTF_GetError());
        return -1;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(game->text_font, "Score: ", game->text_color);
    if(!surface){
        printf("Error creating the surface: %s\n",SDL_GetError());
        return -1;
    }

    game->text_rect.w = surface->w;
    game->text_rect.h = surface->h;
    game->text_img = SDL_CreateTextureFromSurface(game->renderer, surface);

    SDL_FreeSurface(surface);
    if(!game->text_img){
        printf("Error creating the text texture: %s\n",SDL_GetError());
        return -1;
    }

    return 0;
}

void draw_background(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 34, 119, 34, 255);
    SDL_Rect rect = {0,0,640,MARGIN};
    SDL_RenderFillRect(renderer, &rect);
}

void draw_fruit(SDL_Renderer *renderer, fruit_s fruit){
    SDL_Rect rect = {TILE_SIZE * fruit.x, TILE_SIZE * fruit.y + MARGIN, TILE_SIZE, TILE_SIZE};
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_snake(SDL_Renderer *renderer, snake_s *head){
    
    while(head != NULL){
        SDL_SetRenderDrawColor(renderer, 0,0,255,255);
        SDL_Rect rect = {TILE_SIZE * head->x, MARGIN + TILE_SIZE * head->y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 20,20,240,255);
        SDL_RenderDrawRect(renderer, &rect);
        head = head->prev;
    }
}

int print_score(game_t *game, int score){
    char buff[15];
    sprintf(buff, "Score: %d", score);


    SDL_Surface *surface = TTF_RenderText_Blended(game->text_font, buff, game->text_color);
    if(!surface){
        printf("Error creating the surface: %s\n",SDL_GetError());
        return -1;
    }

    game->text_rect.w = surface->w;
    game->text_rect.h = surface->h;
    game->text_rect.x = (WINDOW_WIDTH-game->text_rect.w) / 2;
    game->text_rect.y = (MARGIN-game->text_rect.h)/2;
    game->text_img = SDL_CreateTextureFromSurface(game->renderer, surface);

    SDL_FreeSurface(surface);
    if(!game->text_img){
        printf("Error creating the text texture: %s\n",SDL_GetError());
        return -1;
    }
    SDL_RenderCopy(game->renderer, game->text_img, NULL, &game->text_rect);
    return 0;
}