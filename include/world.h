#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include <vector>
#include "grid.h"
#include "input_group.h"
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
    std::vector<InputGroup*> input_groups;

    const double spawn_radius = 1000.0;
    int num_neurons = 500;

    int num_input_groups = 10;

    const int update_period = 250;

    void create_input_groups();
    void generate_neurons(double spawn_radius, int num_neurons);
};

#endif // WORLD_H