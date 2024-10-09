#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include "color.h"
#include "view.h"

class Grid {
public:
    Grid();
    ~Grid();

    void render(SDL_Renderer *renderer, View *view);

private:
    double grid_spacing;
    Color grid_color;

    void draw_grid(SDL_Renderer *renderer, View *view, double left_x, double right_x, double left_y, double right_y, double spacing);
};

#endif // GRID_H