/** file: src/main.cpp
 * 主文件，负责游戏启动、主循环、退出
 */

# include <SDL2/SDL.h>

# include "../include/game.h"

# undef main


int main() {
    // 初始化
    Game game = Game_Init();

    // 主循环
    bool is_running = true;
    while (is_running) {
        // 遍历事件
        while (SDL_PollEvent(&game.event)) {
            switch (game.event.type) {
                case SDL_QUIT:                  /* 关闭窗口 */
                    is_running = false;
                    break;
            }
        }

        // 渲染
        SDL_SetRenderDrawColor(game.renderer, WINDOW_BACKGROUND_COLOR.r, WINDOW_BACKGROUND_COLOR.g, WINDOW_BACKGROUND_COLOR.b, WINDOW_BACKGROUND_COLOR.a);
        SDL_RenderClear(game.renderer);
        SDL_RenderPresent(game.renderer);
    }

    // 退出
    Game_Quit(game);
    return 0;
}
