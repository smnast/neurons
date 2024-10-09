#include "neuron.h"

Neuron::Neuron(const Vector2D &pos, SDL_Texture *sprite) : position(pos), sprite(sprite) {}

Neuron::~Neuron() {}

void Neuron::randomize_direction() {
    double angle = (double)rand() / RAND_MAX * 2 * M_PI;
    direction = Vector2D(cos(angle), sin(angle));
}

void Neuron::move() {
    position += direction * neuron_speed;
}

void Neuron::render(SDL_Renderer* renderer, View *view) const {
    // Get the texture's width and height
    int width, height;
    SDL_QueryTexture(sprite, nullptr, nullptr, &width, &height);

    // The neuron's rect in world coordinates
    SDL_Rect world_rect;
    world_rect.x = position.x;
    world_rect.y = position.y;
    world_rect.w = width;
    world_rect.h = height;

    // The neuron's rect in view coordinates
    SDL_Rect view_rect = view->world_to_view(world_rect);

    // Render the sprite
    SDL_RenderCopy(renderer, sprite, nullptr, &view_rect);
}