#ifndef OUTPUT_GROUP_H
#define OUTPUT_GROUP_H

#include <SDL2/SDL.h>
#include "color.h"
#include "view.h"

class OutputGroup {
public:
    OutputGroup(Vector2D position);
    ~OutputGroup();

    bool handle_event(SDL_Event &e, View *view);

    void activate();
    void update_activation();

    void render(SDL_Renderer *renderer, View *view);

    double get_dopamine() const;

    Vector2D get_position() const;
    double get_collider_radius() const;

private:
    Color color = Color(0x6B, 0x03, 0xFC, 0x7F);
    Color color_activated = Color(0x03, 0xFC, 0x6B, 0x7F);

    Vector2D position;
    const double radius = 200.0;

    bool next_active = false;
    bool active = false;

    const double dopamine = 1.0;
};

#endif // OUTPUT_GROUP_H