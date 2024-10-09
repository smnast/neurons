#include "grid.h"
#include <iostream>

Grid::Grid() : grid_spacing(40.0), grid_color(Color(0x30, 0x30, 0x30)) {}

Grid::~Grid() {}

void Grid::render(SDL_Renderer *renderer, View *view) {
    SDL_Rect view_rect = view->get_rect();
    double left_x = view_rect.x;
    double right_x = view_rect.x + view_rect.w;
    double top_y = view_rect.y;
    double bottom_y = view_rect.y + view_rect.h;

    draw_grid(renderer, view, left_x, right_x, top_y, bottom_y, grid_spacing);
}

void Grid::draw_grid(SDL_Renderer *renderer, View *view, double left_x, double right_x, double top_y, double bottom_y, double spacing) {
    SDL_SetRenderDrawColor(renderer, grid_color.r, grid_color.g, grid_color.b, grid_color.a);

    double x_start = left_x - fmod(left_x, spacing);
    for (double x = x_start; x <= right_x; x += spacing) {
        Vector2D start = view->world_to_view(Vector2D(x, top_y));
        Vector2D end = view->world_to_view(Vector2D(x, bottom_y));
        SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
    }

    double y_start = top_y - fmod(top_y, spacing);
    for (double y = y_start; y <= bottom_y; y += spacing) {
        Vector2D start = view->world_to_view(Vector2D(left_x, y));
        Vector2D end = view->world_to_view(Vector2D(right_x, y));
        SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
    }
}
