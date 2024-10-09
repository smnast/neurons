#include "output_group.h"
#include <SDL2/SDL2_gfxPrimitives.h>

OutputGroup::OutputGroup(Vector2D position) : position(position) {}

OutputGroup::~OutputGroup() {}

void OutputGroup::activate() {
    next_active = true;
}

void OutputGroup::update_activation() {
    active = next_active;
    next_active = false;
}

void OutputGroup::render(SDL_Renderer* renderer, View* view) {
    Vector2D view_position = view->world_to_view(position);
    double view_radius = view->world_to_view(radius);
    
    Color cur_color = active ? color_activated : color;
    filledCircleRGBA(renderer, view_position.x, view_position.y, view_radius, cur_color.r, cur_color.g, cur_color.b, cur_color.a);
}

Vector2D OutputGroup::get_position() const {
    return position;
}

double OutputGroup::get_collider_radius() const {
    return radius;
}
