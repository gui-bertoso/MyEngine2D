//
// Created by gbertoso on 2025-08-29.
//

#include "Core/Application.h"
#include <iostream>
#include <chrono>
#include <thread>

namespace Engine {
    Application::Application() : isRunning(true) {}

    void Application::processInput() {
        std::cout << "Processing inputs..." << std::endl;
    }

    void Application::update(float deltaTime) {
        std::cout << "Updating game [deltaTime=" << deltaTime << "]" << std::endl;
    }

    void Application::render() {
        std::cout << "Rendering frames..." << std::endl;
    }

    void Application::run() {
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