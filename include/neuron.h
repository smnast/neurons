#ifndef NEURON_H
#define NEURON_H

#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "color.h"
#include "vector.h"
#include "view.h"

class Neuron {
public:
    Neuron(const Vector2D &pos, SDL_Texture *sprite, SDL_Texture *sprite_activated);
    ~Neuron();

    void randomize_direction();
    // eventaully, we will have other functions to control the activations

    void move(double delta_time);
    void collide(const std::vector<Neuron*> &neurons);

    void connect(Neuron *neuron);

    void activate();
    void propagate_activation();
    void update_activation();
    void update_weights();

    bool handle_event(SDL_Event &e, View *view);

    void render_body(SDL_Renderer* renderer, View *view) const;
    void render_connections(SDL_Renderer* renderer, View *view) const;

protected:
    const float collider_radius = 20.0;
    bool active = false;

private:
    Vector2D position;
    SDL_Texture *sprite, *sprite_activated;

    Color connection_color = {0x21, 0x78, 0xAD, 0x7F};
    Color connection_color_activated = {0xCF, 0x94, 0x1F, 0x7F};

    std::unordered_set<Neuron*> connections;
    std::unordered_map<Neuron*, double> connection_weights;
    const double initial_connection_weight = 0.0;

    double modified_sigmoid(double x) const;
    double sigmoid(double x) const;

    bool prev_active = false;
    double activation = 0.0;
    double threshold = 1.0;

    const double hebbian_increase = 1.0;
    const double hebbian_decrease = 0.1;
    const double max_weight = 5.0;
    const double min_weight = -5.0;

    const int refractory_period = 5;
    int cur_refractory_period = 0;

    // Added to the connection weight to ensure positive values
    const double line_width_offset = 0.4;

    Vector2D direction;
    const float neuron_speed = 50.0;
};

#endif // NEURON_H