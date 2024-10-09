#ifndef NEURON_H
#define NEURON_H

#include <SDL2/SDL.h>
#include <vector>
#include "vector.h"
#include "view.h"

class Neuron {
public:
    Neuron(const Vector2D &pos, SDL_Texture *sprite);
    ~Neuron();

    void randomize_direction();
    // eventaully, we will have other functions to control the activations

    void move();
    void collide(const std::vector<Neuron> &neurons);

    void render(SDL_Renderer* renderer, View *view) const;

protected:
    const float collider_radius = 40.0;

private:
    Vector2D position;
    SDL_Texture *sprite;

    Vector2D direction;
    const float neuron_speed = 0.005;
};

#endif // NEURON_H