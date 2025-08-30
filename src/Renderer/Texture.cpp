//
// Created by gbertoso on 2025-08-29.
//

#include "Renderer/Texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>

namespace Engine {
    Texture::Texture(SDL_Renderer *renderer)
        : renderer(renderer),
        texture(nullptr),
        width(0),
        height(0) {}

    Texture::~Texture() {
        if (texture) SDL_DestroyTexture(texture);
    }

    bool Texture::loadFromFile(const std::string &path) {
        SDL_Surface* surface = IMG_Load(path.c_str()); // Can use IMG_load

        if (!surface) {
            std::cerr << "Failed to load image [" << IMG_GetError() << "]" << std::endl;
            return false;
        }

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        width = surface->w;
        height = surface->h;
        SDL_FreeSurface(surface);
        return true;
    }

    void Texture::render(int x, int y, int w, int h) {
        SDL_Rect dst;
        dst.x = x;
        dst.y = y;
        dst.w = (w == 0) ? width : w;
        dst.h = (h == 0) ? height : h;
        SDL_RenderCopy(renderer, texture, nullptr, &dst);
    }



}