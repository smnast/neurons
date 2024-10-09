#ifndef NEURON_H
#define NEURON_H

#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>
#include "color.h"
#include "vector.h"
#include "view.h"

class Neuron {
public:
    Neuron(const Vector2D &pos, SDL_Texture *sprite);
    ~Neuron();

    void randomize_direction();
    // eventaully, we will have other functions to control the activations

    void move();
    void collide(const std::vector<Neuron*> &neurons);

    void connect(Neuron *neuron);

    void render_body(SDL_Renderer* renderer, View *view) const;
    void render_connections(SDL_Renderer* renderer, View *view) const;

protected:
    const float collider_radius = 40.0;

private:
    Vector2D position;
    SDL_Texture *sprite;

    Color connection_color = {0x21, 0x78, 0xAD, 0x7F};
    Color connection_color_activated = {0xCF, 0x94, 0x1F, 0x7F};

    std::unordered_set<Neuron*> connections;

    Vector2D direction;
    const float neuron_speed = 0.005;
};

#endif // NEURON_H