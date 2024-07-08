#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

namespace MotasEngine {
constexpr uint32_t FPS = 60;
constexpr uint32_t MILLISECS_PER_FRAME = 1000.0 / FPS;

class Game {
private:
  bool isRunning;
  uint32_t millisecsPreviousFrame = 0;
  SDL_Window *window;
  SDL_Renderer *renderer;

public:
  Game();
  ~Game();
  void Initialize();
  void Run();
  void ProcessInput();
  void Setup();
  void Update();
  void Render();
  void Destroy();

  uint32_t windowWidth;
  uint32_t windowHeight;
};
} // namespace MotasEngine
#endif
