/** file: include/color.h\n
 * 头文件，负责颜色RGBa信息
 */

# ifndef POINT_GAME_CPP_COLOR_H
# define POINT_GAME_CPP_COLOR_H

# include <SDL2/SDL.h>

// 颜色信息
typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;

// 颜色
const Color BLACK = {0, 0, 0, SDL_ALPHA_OPAQUE};
const Color WHITE = {255, 255, 255, SDL_ALPHA_OPAQUE};

# endif //POINT_GAME_CPP_COLOR_H
