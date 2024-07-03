#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
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

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::Setup() {
    playerPosition = glm::vec2(10.0, 20.0);
    playerVelocity = glm::vec2(100.0, 0.0);
}
void Game::Update() {
    // Wast time untill we enough time has passed
    uint32_t timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame); 
    if (timeToWait <= MILLISECS_PER_FRAME)
        SDL_Delay(timeToWait);
    
    float deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0f;
    if (deltaTime > MILLISECS_PER_FRAME / 1000.0f)
        deltaTime = MILLISECS_PER_FRAME / 1000.0f; 
   
    // Store Current frame time
    millisecsPreviousFrame = SDL_GetTicks();
    playerPosition += playerVelocity * deltaTime;
}
void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // Loads a Png texture
    //SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
    //SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    //SDL_FreeSurface(surface);
    SDL_Texture* texture = IMG_LoadTexture(renderer, "./assets/images/tank-tiger-right.png");

    // Destination rectangle that we want to place our texture on
    SDL_Rect dstRect = { 
        static_cast<int>(playerPosition.x),
        static_cast<int>(playerPosition.y), 
        32, 
        32 
    };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);

    SDL_RenderPresent(renderer); 
}
void Game::Run() {
    Setup();
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

