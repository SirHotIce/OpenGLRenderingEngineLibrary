//
// Created by Vinayak Regmi on 24/04/2025.
//

#ifndef MESH_H
#define MESH_H
#include <vector>

#include "Vertex.h"

namespace MeshHandling {

    struct Mesh {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
};

} // MeshHandling

#endif //MESH_H
