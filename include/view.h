#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include "vector.h"

class View {
public:
    View();
    ~View();

    void zoom(double amount);
    void pan(double x, double y);
    
    bool handle_event(SDL_Event &e);

    Vector2D world_to_view(Vector2D world_position);
    SDL_Rect world_to_view(SDL_Rect world_rect);

    Vector2D get_position();
    SDL_Rect get_rect();

private:
    float zoom_amount;
    const float zoom_speed = 1.1;
    const float camera_width = 800; // TODO: don't hardcode these values
    const float camera_height = 600; // TODO: don't hardcode these values
    const float max_zoom = 10.0;
    const float min_zoom = 0.1;

    bool mouse_dragging = false;
    Vector2D last_mouse_position;

    Vector2D position;
};

#endif // VIEW_H