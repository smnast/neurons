#ifndef INPUT_GROUP_H
#define INPUT_GROUP_H

#include <SDL2/SDL.h>
#include "color.h"
#include "neuron.h"
#include "view.h"

class InputGroup {
public:
    InputGroup(Vector2D position);
    ~InputGroup();

    bool handle_event(SDL_Event &e, View *view);

    void activate();
    void propagate_activation(std::vector<Neuron*> &neurons);
    void update_activation();

    void render(SDL_Renderer *renderer, View *view);

private:
    Color color = Color(0x5E, 0xFA, 0xFF, 0x7F);
    Color color_activated = Color(0xFF, 0xB6, 0x38, 0x7F);

    Vector2D position;
    const double radius = 200.0;

    bool next_active = false;
    bool active = false;
};

#endif // INPUT_GROUP_H