#include "texture_manager.h"
#include <iostream>

void TextureManager::load_textures(SDL_Renderer *renderer) {
    load_texture("neuron", "assets/images/neuron.png", renderer);
}

bool TextureManager::load_texture(const std::string &id, const std::string &filePath, SDL_Renderer *renderer) {
    // Load the image into an SDL_Surface
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return false;
    }

    // Create a texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    texture_map[id] = texture;
    return true;
}

SDL_Texture* TextureManager::get_texture(const std::string &id) const {
    auto it = texture_map.find(id);
    if (it != texture_map.end()) {
        return it->second;
    }
    return nullptr;
}

void TextureManager::clean_up() {
    for (auto& pair : texture_map) {
        SDL_DestroyTexture(pair.second);
    }
    texture_map.clear();
}

TextureManager::~TextureManager() {
    clean_up();
}