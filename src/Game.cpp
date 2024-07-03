#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
    windowWidth = 800;
    windowHeight = 600;

    window = SDL_CreateWindow(
        NULL, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        windowWidth, 
        windowHeight,
        SDL_WINDOW_BORDERLESS /*||
        SDL_WINDOW_FULLSCREEN*/
    );
    if (!window) {
        std::cerr << "Error creating SDL Window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Error Creating SDL Window." << std::endl;
        return;
    }

    if (SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN != 0)) {
        std::cerr << "Error in setting fullscreen." << std::endl;
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

double playerPositionX = 10.0;
double PlayerPositionY = 20.0;
void Game::Setup() {
    // TODO: Initialize game objects
}
void Game::Update() {
    // TODO: Update game objects
    playerPositionX += 1.0;
    playerPositionY += 1.0;
}
void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // Loads a Png texture
    SDL_Texture* texture = IMG_LoadTexture(renderer, "./assets/images/tank-tiger-right.png");

    // Destination rectangle that we want to place our texture on
    SDL_Rect dstRect = { 10, 10, 32, 32 };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);

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

