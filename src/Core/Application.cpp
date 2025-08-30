//
// Created by gbertoso on 2025-08-29.
//

#include "Core/Application.h"
#include <iostream>
#include <chrono>
#include <thread>

namespace Engine {
    Application::Application() : isRunning(true), window(nullptr), renderer(nullptr) {}

    Application::~Application() {
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Application::processInput() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) { // Equal pygame event logics
                quit();
            }
        }
    }

    void Application::update(float deltaTime) {
        // Logics here
    }

    void Application::render() {
        // Clear a screen with a color
        SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
        SDL_RenderClear(renderer);

        // Draw some itens here (sprites, forms, etc), before SDL Render Present line

        SDL_RenderPresent(renderer); // Type a pygame.window update/flip
    }

    void Application::run() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialized [SDL_ERROR:" << SDL_GetError() << "]" << std::endl;
            return;
        }

        window = SDL_CreateWindow(
            "Engine",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            800, 600,
            SDL_WINDOW_SHOWN
            );

        if (!window) {
            std::cerr << "Window could not be created [SDL_ERROR:" << SDL_GetError() << "]" << std::endl;
            SDL_Quit();
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


        using clock = std::chrono::high_resolution_clock;
        auto lastTime = clock::now();

        while (isRunning) {
            auto now = clock::now();
            float deltaTime = std::chrono::duration<float>(now - lastTime).count();
            lastTime = now;

            processInput();
            update(deltaTime);
            render();

            std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Makes a maximum frame rate to ~60
        }
    }

    void Application::quit() {
        isRunning = false;
    }
}