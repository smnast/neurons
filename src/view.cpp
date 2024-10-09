#include "view.h"

View::View() : zoom_amount(1.0), position(Vector2D(0, 0)) {}

View::~View() {}

void View::zoom(double amount) {
    zoom_amount *= amount;
}

void View::pan(double x, double y) {
    position.x = position.x + x;
    position.y = position.y + y;
}

bool View::handle_event(SDL_Event &e) {
    if (e.type == SDL_MOUSEWHEEL) {
        if (e.wheel.y > 0) {
            zoom(zoom_speed);
        } else if (e.wheel.y < 0) {
            zoom(1 / zoom_speed);
        } else {
            return false;
        }
    } else if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            mouse_dragging = true;
            last_mouse_position = Vector2D(e.button.x, e.button.y);
        } else {
            return false;
        }
    } else if (e.type == SDL_MOUSEBUTTONUP) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            mouse_dragging = false;
        } else {
            return false;
        }
    } else if (e.type == SDL_MOUSEMOTION) {
        if (mouse_dragging) {
            Vector2D current_mouse_position(e.motion.x, e.motion.y);
            Vector2D delta = current_mouse_position - last_mouse_position;
            Vector2D view_movement = delta * -1 / zoom_amount;
            pan(view_movement.x, view_movement.y);
            last_mouse_position = current_mouse_position;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

Vector2D View::world_to_view(Vector2D world_position) {
    // Adjust world position to be relative to the camera position
    float view_x = (world_position.x - position.x) * zoom_amount + (camera_width / 2);
    float view_y = (world_position.y - position.y) * zoom_amount + (camera_height / 2);

    return Vector2D(view_x, view_y);
}

SDL_Rect View::world_to_view(SDL_Rect world_rect) {
    // Convert the center of the rectangle to view coordinates
    Vector2D center(world_rect.x, world_rect.y);
    Vector2D view_center = world_to_view(center);

    // Calculate the size of the rectangle in view coordinates
    int view_w = static_cast<int>(world_rect.w * zoom_amount);
    int view_h = static_cast<int>(world_rect.h * zoom_amount);

    return SDL_Rect{
        static_cast<int>(view_center.x - view_w / 2),
        static_cast<int>(view_center.y - view_h / 2),
        view_w,
        view_h
    };
}

Vector2D View::get_position() {
    return position;
}

SDL_Rect View::get_rect() {
    return SDL_Rect{
        static_cast<int>(position.x - (camera_width / 2) / zoom_amount),
        static_cast<int>(position.y - (camera_height / 2) / zoom_amount),
        static_cast<int>(camera_width / zoom_amount),
        static_cast<int>(camera_height / zoom_amount)
    };
}
