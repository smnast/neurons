#include "world.h"
#include "texture_manager.h"

World::World() {
    view = new View();
}

World::~World() {
    delete view;
}

void World::init() {
    generate_neurons(spawn_radius, num_neurons);

    SDL_AddTimer(update_period, [](Uint32 interval, void *param) -> Uint32 {
        World *world = static_cast<World*>(param);
        world->update();
        return interval;
    }, this);
}

void World::update() {
    for (Neuron *neuron : neurons) {
        neuron->randomize_direction();
    }
}

void World::step(double delta_time) {
    for (Neuron *neuron : neurons) {
        neuron->move();
        neuron->collide(neurons);
    }
}

void World::render(SDL_Renderer *renderer) {
    grid.render(renderer, view);
    for (Neuron *neuron : neurons) {
        neuron->render_connections(renderer, view);
    }
    for (Neuron *neuron : neurons) {
        neuron->render_body(renderer, view);
    }
}

void World::handle_event(SDL_Event &e) {
    if (view->handle_event(e)) return;
}

void World::generate_neurons(double spawn_radius, int num_neurons) {
    TextureManager &texture_manager = TextureManager::get_instance();
    SDL_Texture *neuron_texture = texture_manager.get_texture("neuron");

    for (int i = 0; i < num_neurons; i++) {
        double angle = (double)rand() / RAND_MAX * 2 * M_PI;
        double radius = (double)rand() / RAND_MAX * spawn_radius;
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        Vector2D position(x, y);
        neurons.push_back(new Neuron(position, neuron_texture));
    }
}