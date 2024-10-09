#include "neuron.h"
#include <SDL2/SDL2_gfxPrimitives.h>

Neuron::Neuron(const Vector2D &pos, SDL_Texture *sprite) : position(pos), sprite(sprite) {}

Neuron::~Neuron() {}

void Neuron::randomize_direction() {
    double angle = (double)rand() / RAND_MAX * 2 * M_PI;
    direction = Vector2D(cos(angle), sin(angle));
}

void Neuron::move() {
    position += direction * neuron_speed;
}

void Neuron::collide(const std::vector<Neuron*> &neurons) {
    for (Neuron *neuron : neurons) {
        if (neuron == this) {
            continue;
        }

        Vector2D diff = position - neuron->position;
        double distance = diff.magnitude();

        if (distance < collider_radius) {
            // Connect the neurons
            this->connect(neuron);

            // Push them away from each other
            double overlap = collider_radius - distance;
            Vector2D direction = diff / distance;
            position += direction * overlap / 2;
            neuron->position -= direction * overlap / 2;
        }
    }
}

void Neuron::connect(Neuron *neuron) {
    connections.insert(neuron);
}

void Neuron::render_body(SDL_Renderer* renderer, View *view) const {
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

void Neuron::render_connections(SDL_Renderer* renderer, View *view) const {
    for (Neuron *neuron : connections) {
        // The line's start and end points in world coordinates
        Vector2D start = position;
        Vector2D end = neuron->position;

        // The line's start and end points in view coordinates
        Vector2D view_start = view->world_to_view(start);
        Vector2D view_end = view->world_to_view(end);

        // Render the line
        Color line_color = connection_color;
        Uint8 line_width = view->world_to_view(2.0);
        thickLineRGBA(renderer, view_start.x, view_start.y, view_end.x, view_end.y, line_width, line_color.r, line_color.g, line_color.b, line_color.a);
    }
}