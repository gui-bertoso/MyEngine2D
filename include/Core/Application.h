//
// Created by gbertoso on 2025-08-29.
//
#pragma once

#ifdef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

void Engine() {
    class Application {
    public:
        Application();
        void run();
        void quit();
    private:
        bool isRunning;
        void processInput();
        void update();
        void render();
    };
}

#endif