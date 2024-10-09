#include "world.h"

World::World() {
    view = new View();
}

World::~World() {
    delete view;
}

void World::update() {}

void World::render(SDL_Renderer *renderer) {
    grid.render(renderer, view);
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 50;
    rect.h = 50;
    rect = view->world_to_view(rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

{
    SDL_Rect rect;
    rect.x = 200;
    rect.y = 200;
    rect.w = 50;
    rect.h = 50;
    rect = view->world_to_view(rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
}

void World::handle_event(SDL_Event &e) {
    if (view->handle_event(e)) return;
}