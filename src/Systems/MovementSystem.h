#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "../ECS/ECS.h"

namespace MotasEngine {
class MovementSystem : public System {
public:
  MovementSystem() {
    // TODO: RequireComponent<TransformComponent>();
    // TODO: RequireComponent<..>();
  }

  void Update(deltaTime) {
    // TODO:
    // Loop all entities that the system is interested in
    for (auto &entity : GetEntities()) {
      // TODO: Update entity position based on its velocity and deltaTime
    }
  }
};
} // namespace MotasEngine
#endif
