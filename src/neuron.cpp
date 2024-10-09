#include "neuron.h"
#include <SDL2/SDL2_gfxPrimitives.h>

Neuron::Neuron(const Vector2D &pos, SDL_Texture *sprite, SDL_Texture *sprite_activated) : position(pos), sprite(sprite), sprite_activated(sprite_activated) {}

Neuron::~Neuron() {}

void Neuron::randomize_direction() {
    double angle = (double)rand() / RAND_MAX * 2 * M_PI;
    direction = Vector2D(cos(angle), sin(angle));
}

void Neuron::move(double delta_time) {
    position += direction * neuron_speed * delta_time;
}

void Neuron::collide(const std::vector<Neuron*> &neurons) {
    for (Neuron *neuron : neurons) {
        if (neuron == this) {
            continue;
        }

        Vector2D diff = position - neuron->position;
        double distance = diff.magnitude();

        double total_collider_distance = collider_radius + neuron->collider_radius;

        if (distance < total_collider_distance) {
            // Connect the neurons
            this->connect(neuron);

            // Push them away from each other
            double overlap = total_collider_distance - distance;
            Vector2D direction = diff / distance;
            position += direction * overlap / 2;
            neuron->position -= direction * overlap / 2;
        }
    }
}

void Neuron::connect(Neuron *neuron) {
    connections.insert(neuron);
    connection_weights[neuron] = initial_connection_weight;
}

void Neuron::activate() {
    activation = std::numeric_limits<double>::infinity();
}

void Neuron::propagate_activation() {
    if (!active) {
        return;
    }

    for (Neuron *neuron : connections) {
        neuron->activation += modified_sigmoid(connection_weights.at(neuron));
    }
}

void Neuron::update_activation() {
    prev_active = active;
    active = activation >= threshold && cur_refractory_period == 0;
    activation = 0.0;

    if (cur_refractory_period > 0) {
        cur_refractory_period--;
    }

    if (active) {
        cur_refractory_period = refractory_period;
    }
}

void Neuron::update_weights() {
    if (this->prev_active) {
        for (Neuron *neuron : connections) {
            if (neuron->active) {
                connection_weights[neuron] += hebbian_increase;
                connection_weights[neuron] = std::min(connection_weights[neuron], max_weight);
            } else {
                connection_weights[neuron] -= hebbian_decrease;
                connection_weights[neuron] = std::max(connection_weights[neuron], min_weight);
            }
        }
    }
}

void Neuron::render_body(SDL_Renderer* renderer, View *view) const {
    SDL_Texture *cur_sprite = active ? sprite_activated : sprite;

    // Get the texture's width and height
    int width, height;
    SDL_QueryTexture(cur_sprite, nullptr, nullptr, &width, &height);

    // The neuron's rect in world coordinates
    SDL_Rect world_rect;
    world_rect.x = position.x;
    world_rect.y = position.y;
    world_rect.w = width;
    world_rect.h = height;

    // The neuron's rect in view coordinates
    SDL_Rect view_rect = view->world_to_view(world_rect);

    // Render the sprite
    SDL_RenderCopy(renderer, cur_sprite, nullptr, &view_rect);
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
        Color line_color = active ? connection_color_activated : connection_color;
        Uint8 line_width = view->world_to_view(modified_sigmoid(connection_weights.at(neuron)) + line_width_offset);
        thickLineRGBA(renderer, view_start.x, view_start.y, view_end.x, view_end.y, line_width, line_color.r, line_color.g, line_color.b, line_color.a);
    }
}

Vector2D Neuron::get_position() const {
    return position;
}

double Neuron::get_collider_radius() const {
    return collider_radius;
}

double Neuron::modified_sigmoid(double x) const {
    return sigmoid(x) * 2 - 0.3;
}

double Neuron::sigmoid(double x) const {
    return 1 / (1 + exp(-x));
}