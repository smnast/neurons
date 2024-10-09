#ifndef COLOR_H
#define COLOR_H

#include <SDL2/SDL.h>

class Color {
public:
    Color();
    Color(Uint8 x, Uint8 y, Uint8 z);
    Color(Uint8 x, Uint8 y, Uint8 z, Uint8 a);
    ~Color();

    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};

#endif // COLOR_H
