#include "./Game/Game.h"
#include <iostream>

int main() {
  MotasEngine::Game game;
  game.Initialize();
  game.Run();
  game.Destroy();

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
