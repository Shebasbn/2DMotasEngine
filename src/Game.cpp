#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game() {
    // TODO:...
    std::cout << "Calling Game constructor!" << std::endl;
    isRunning = false;
}
Game::~Game() {
    // TODO:..
    std::cout << "Calling Game Destructor!" << std::endl;
}

void Game::Initialize() {
    std::cout << "Initializing Game!" << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;

    window = SDL_CreateWindow(
        NULL, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        windowWidth, 
        windowHeight,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        std::cerr << "Error creating SDL Window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error Creating SDL Window." << std::endl;
        return;
    }
    
    isRunning = true;
}
void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) 
                    isRunning = false;
                break;
        }
    }
}
void Game::Update() {
    // 
}
void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

   SDL_RenderPresent(renderer); 
}
void Game::Run() {
    while (isRunning) {
        ProcessInput();
        Update();
        Render();    
    }
}
void Game::Destroy() {
    std::cout << "Destroying Game!" << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

