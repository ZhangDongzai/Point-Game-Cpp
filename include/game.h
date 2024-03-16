/** file: include/game.h
 * 头文件，负责游戏启动、退出
 */

# ifndef POINT_GAME_CPP_GAME_H
# define POINT_GAME_CPP_GAME_H

# include <SDL2/SDL.h>
# include <cstdio>

# include "setting.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
} Game;

Game Game_Init() {
    // 初始化 SDL
    Game game;
    int init_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (init_code < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        exit(-1);
    }
    game.window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (game.window == NULL) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);
    if (game.renderer == NULL) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(game.window);
        SDL_Quit();
        exit(-1);
    }
    return game;
}

void Game_Quit(Game game) {
    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
}

# endif //POINT_GAME_CPP_GAME_H
