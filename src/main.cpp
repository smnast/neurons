#include <SDL2/SDL.h>
#include "texture_manager.h"
#include "world.h"
#include "view.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Grid Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    TextureManager &texture_manager = TextureManager::get_instance();
    texture_manager.load_textures(renderer);

    World world;
    world.init();

    bool quit = false;
    SDL_Event e;

    Uint32 last_time = SDL_GetTicks();
    while (!quit) {
        Uint32 current_time = SDL_GetTicks();
        double delta_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else {
                world.handle_event(e);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0x24, 0x24, 0x24, 0xFF);
        SDL_RenderClear(renderer);

        world.step(delta_time);
        world.render(renderer);

        SDL_RenderPresent(renderer);
    
        last_time = current_time;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
