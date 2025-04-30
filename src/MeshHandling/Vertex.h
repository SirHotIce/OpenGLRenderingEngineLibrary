#ifndef VERTEX_H
#define VERTEX_H
#include <glm/glm.hpp>
namespace MeshHandling {
    struct Vertex {
        glm::vec3 Position;
        glm::vec2 TexCoords;
        glm::vec3 Normal;
    };
}
#endif