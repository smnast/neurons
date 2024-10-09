#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include <vector>
#include "grid.h"
#include "neuron.h"
#include "view.h"

class World {
public:
    World();
    ~World();

    void init();

    void update();
    void step(double delta_time);

    void render(SDL_Renderer *renderer);
    void handle_event(SDL_Event &e);

private:
    View *view;
    Grid grid;
    std::vector<Neuron*> neurons;
    const double spawn_radius = 100.0;
    int num_neurons = 10;

    const int update_period = 250;

    void generate_neurons(double spawn_radius, int num_neurons);
};

#endif // WORLD_H