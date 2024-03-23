/** file: include/game.h\n
 * 头文件，负责游戏启动、退出
 */

# ifndef POINT_GAME_CPP_GAME_H
# define POINT_GAME_CPP_GAME_H

# include <SDL2/SDL.h>
# include <cstdio>

# include "setting.h"


class Game {
public:
    Game();
    ~Game();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    void mainLoop();
};

# endif //POINT_GAME_CPP_GAME_H
