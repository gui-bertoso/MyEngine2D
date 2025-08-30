//
// Created by gbertoso on 2025-08-29.
//
#pragma once
#include <SDL2/SDL.h>

namespace Engine {
    class Application {
    public:
        Application(); // Constructor??
        ~Application();
        void run(); // Main loop
        void quit(); // Stop a loop here
    private:
        bool isRunning; // Game state
        void processInput(); // Processes input
        void update(float deltaTime); // Updates / game logic
        void render(); // Renderization

        SDL_Window* window;
        SDL_Renderer* renderer;
    };
}
