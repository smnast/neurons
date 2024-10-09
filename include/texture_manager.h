#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class TextureManager {
public:
    static TextureManager &get_instance() {
        static TextureManager instance;
        return instance;
    }

    // Delete copy constructor and assignment operator to ensure singleton property
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    void load_textures(SDL_Renderer *renderer);

    // Retrieves a texture by its ID
    SDL_Texture *get_texture(const std::string &id) const;

    // Cleans up all loaded textures
    void clean_up();

private:
    TextureManager() = default;
    ~TextureManager();

    std::map<std::string, SDL_Texture*> texture_map;

    // Loads a texture from a file path and stores it in the map
    bool load_texture(const std::string &id, const std::string &filePath, SDL_Renderer *renderer);
};

#endif // TEXTURE_MANAGER_H