#include "input_group.h"
#include <SDL2/SDL2_gfxPrimitives.h>

InputGroup::InputGroup(Vector2D position) : position(position) {}

InputGroup::~InputGroup() {}

bool InputGroup::handle_event(SDL_Event &e, View *view) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            Vector2D mouse_position(x, y);

            Vector2D view_position = view->world_to_view(position);

            Vector2D diff = mouse_position - view_position;
            double distance = diff.magnitude();

            double view_radius = view->world_to_view(radius);

            if (distance < view_radius) {
                activate();
                return true;
            }
        }
    }

    return false;
}

void InputGroup::activate() {
    next_active = true;
}

void InputGroup::propagate_activation(std::vector<Neuron*> &neurons) {
    if (active) {
        // Activate neurons within the input group's collider
        for (Neuron *neuron : neurons) {
            Vector2D diff = position - neuron->get_position();
            double distance = diff.magnitude();

            double total_collider_distance = radius + neuron->get_collider_radius();
            if (distance < total_collider_distance) {
                neuron->activate();
            }
        }
    }
}

void InputGroup::update_activation() {
    active = next_active;
    next_active = false;
}

void InputGroup::render(SDL_Renderer* renderer, View* view) {
    Vector2D view_position = view->world_to_view(position);
    double view_radius = view->world_to_view(radius);
    
    Color cur_color = active ? color_activated : color;
    filledCircleRGBA(renderer, view_position.x, view_position.y, view_radius, cur_color.r, cur_color.g, cur_color.b, cur_color.a);
}
