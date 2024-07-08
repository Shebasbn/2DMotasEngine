#include "Game.h"
#include "../ECS/ECS.h"
#include "../Logger/Logger.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

namespace MotasEngine {
Game::Game() {
  Logger::Log("Game constructor called!");
  isRunning = false;
}
Game::~Game() { Logger::Log("Game destructor called!"); }

void Game::Initialize() {
  Logger::Log("Initializing Game!");
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    Logger::Error("Error initializing SDL.");
    return;
  }

  SDL_DisplayMode displayMode;
  SDL_GetCurrentDisplayMode(0, &displayMode);
  windowWidth = 800;
  windowHeight = 600;

  window =
      SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       windowWidth, windowHeight, SDL_WINDOW_BORDERLESS /*||
                                                  SDL_WINDOW_FULLSCREEN*/
      );
  if (!window) {
    Logger::Error("Error creating SDL Window.");
    return;
  }

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    Logger::Error("Error Creating SDL renderer.");
    return;
  }

  if (SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN != 0)) {
    Logger::Error("Error in setting fullscreen.");
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

void Game::Setup() {
  // TODO:
  // Entity tank = registry.CreateEntity();
  // tank.AddComponent<TransformComponent>();
  // tank.AddComponent<BoxColliderComponent>();
  // tank.AddComponent<SpriteComponent>("./assets/images/tank.png");
}
void Game::Update() {
  // Waste time untill we enough time has passed
  uint32_t timeToWait =
      MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
  if (timeToWait <= MILLISECS_PER_FRAME)
    SDL_Delay(timeToWait);

  float deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0f;
  if (deltaTime > MILLISECS_PER_FRAME / 1000.0f)
    deltaTime = MILLISECS_PER_FRAME / 1000.0f;

  // Store Current frame time
  millisecsPreviousFrame = SDL_GetTicks();

  // TODO:
  // MovementSystem.Update();
  // CollisionSystem.Update();
  // DamageSystem.Update();
}
void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);

  // TODO: Render game objects...

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
  Logger::Log("Destroying Game!");
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
} // namespace MotasEngine
