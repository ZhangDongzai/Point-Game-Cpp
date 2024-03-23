/** file: include/game.cpp\n
 * 头文件中类函数实现
 */

# include <SDL2/SDL.h>
# include <cstdio>

# include "../include/game.h"
# include "../include/setting.h"


/** Game类构造方法实现 */
Game::Game() {
    int init_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (init_code < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        exit(-1);
    }
    this->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (this->window == nullptr) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        exit(-1);
    }

    this->mainLoop();
}

/** Game类销毁方法实现 */
Game::~Game() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

/** Game类主循环方法实现 */
void Game::mainLoop() {
    bool is_running = true;
    while (is_running) {
        while (SDL_PollEvent(&this->event)) {   /* 遍历事件 */
            switch (this->event.type) {
                case SDL_QUIT:                  /* 关闭窗口 */
                    is_running = false;
                    break;
            }
        }

        // 渲染
        SDL_SetRenderDrawColor(this->renderer, WINDOW_BACKGROUND_COLOR.r, WINDOW_BACKGROUND_COLOR.g, WINDOW_BACKGROUND_COLOR.b, WINDOW_BACKGROUND_COLOR.a);
        SDL_RenderClear(this->renderer);
        SDL_RenderPresent(this->renderer);
    }
}
