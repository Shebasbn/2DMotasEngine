#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <glm/glm.hpp>

namespace MotasEngine {
typedef glm::vec2 Position;
typedef glm::vec2 Scale;
typedef float Rotation;

struct TransformComponent {
  Position position;
  Scale scale;
  Rotation rotation;
};
} // namespace MotasEngine

#endif
