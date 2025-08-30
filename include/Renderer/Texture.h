//
// Created by gbertoso on 2025-08-29.
//

#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace Engine {
    class Texture {
    public:
        Texture(SDL_Renderer* renderer);
        ~Texture();

        bool loadFromFile(const std::string& path); // Load a png or JPG file
        void render(int x, int y, int w = 0, int h = 0); // Render a image in screen
    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        int width;
        int height;
    };
}