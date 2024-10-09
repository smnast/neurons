#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include "vector.h"

#define INIT_WINDOW_WIDTH 800
#define INIT_WINDOW_HEIGHT 600

class View {
public:
    View();
    ~View();

    void zoom(double amount);
    void pan(double x, double y);
    
    bool handle_event(SDL_Event &e);

    Vector2D world_to_view(Vector2D world_position);
    SDL_Rect world_to_view(SDL_Rect world_rect);
    double world_to_view(double world_size);

    Vector2D get_position();
    SDL_Rect get_rect();

private:
    float zoom_amount;
    const float zoom_speed = 1.1;
    float camera_width = INIT_WINDOW_WIDTH;
    float camera_height = INIT_WINDOW_HEIGHT;
    const float max_zoom = 10.0;
    const float min_zoom = 0.1;

    bool mouse_dragging = false;
    Vector2D last_mouse_position;

    Vector2D position;
};

#endif // VIEW_H