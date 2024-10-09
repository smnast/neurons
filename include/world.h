#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include "grid.h"
#include "view.h"

class World {
public:
    World();
    ~World();

    void update();
    void render(SDL_Renderer *renderer);
    void handle_event(SDL_Event &e);

private:
    View *view;
    Grid grid;
};

#endif // WORLD_H