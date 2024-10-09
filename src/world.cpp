#include "world.h"
#include "texture_manager.h"

World::World() {
    view = new View();
}

World::~World() {
    delete view;
}

void World::init() {
    create_input_groups();
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

    for (InputGroup *input_group : input_groups) {
        input_group->propagate_activation(neurons);
    }
    for (Neuron *neuron : neurons) {
        neuron->propagate_activation();
    }

    for (InputGroup *input_group : input_groups) {
        input_group->update_activation();
    }
    for (Neuron *neuron : neurons) {
        neuron->update_activation();
    }

    for (Neuron *neuron : neurons) {
        neuron->update_weights();
    }
}

void World::step(double delta_time) {
    for (Neuron *neuron : neurons) {
        neuron->move(delta_time);
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
    for (InputGroup *input_group : input_groups) {
        input_group->render(renderer, view);
    }
}

void World::handle_event(SDL_Event &e) {
    for (InputGroup *input_group : input_groups) {
        if (input_group->handle_event(e, view)) return;
    }
    if (view->handle_event(e)) return;
}

void World::create_input_groups() {
    for (int i = 0; i < num_input_groups; i++) {
        double angle = (double)i / num_input_groups * 2 * M_PI;
        double x = spawn_radius * cos(angle);
        double y = spawn_radius * sin(angle);
        Vector2D position(x, y);
        input_groups.push_back(new InputGroup(position));
    }
}

void World::generate_neurons(double spawn_radius, int num_neurons) {
    TextureManager &texture_manager = TextureManager::get_instance();
    SDL_Texture *neuron_texture = texture_manager.get_texture("neuron");
    SDL_Texture *neuron_activated_texture = texture_manager.get_texture("neuron_activated");

    for (int i = 0; i < num_neurons; i++) {
        double angle = (double)rand() / RAND_MAX * 2 * M_PI;
        // sqrt(rand) gets uniformly distributed coords in a circle (https://stackoverflow.com/a/50746409)
        double radius = std::sqrt((double)rand() / RAND_MAX * spawn_radius * spawn_radius);
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        Vector2D position(x, y);
        neurons.push_back(new Neuron(position, neuron_texture, neuron_activated_texture));
    }
}