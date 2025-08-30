//
// Created by gbertoso on 2025-08-29.
//
#pragma once

namespace Engine {
    class Application {
    public:
        Application(); // Constructor??
        void run(); // Main loop
        void quit(); // Stop a loop here
    private:
        bool isRunning; // Game state
        void processInput(); // Processes input
        void update(float deltaTime); // Updates / game logic
        void render(); // Renderization
    };
}
